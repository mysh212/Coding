// Author : ysh
// 2023/08/09 Wed 16:39:33
// https://atcoder.jp/contests/abc309/tasks/abc309_f
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#include<fast>
int offline(vector<vector<int>>&f) {
    vector<int>v;
    for(auto &i : f) {
        for(int &j : i) {
            v.push_back(j);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for(auto &i : f) {
        for(int &j : i) {
            j = int(lower_bound(v.begin(),v.end(),j) - v.begin());
        }
    }
    return v.size();
}
int n;
vector<int>f;
vector<int>v;
queue<pair<int,int>>re;
#define left(i) ((i << 1))
#define right(i) ((i << 1) | 1)
void add(int x,int v,int t = 1,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl == nr) return re.push({t,max(f.at(t),v)}),void();
    int mid = (nl + nr) >> 1;
    if(mid >= x) add(x,v,left(t),nl,mid);
    else add(x,v,right(t),mid + 1,nr);
    // re.push({t,-1});
    return;
}
int check(int l,int r,int t = 1,int nl = -1,int nr = -1) {
    if(l > r) return 0;
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl > r || nr < l) return 0;
    if(nl >= l && nr <= r) return f.at(t);
    int mid = (nl + nr) >> 1;
    return max(check(l,r,left(t),nl,mid),check(l,r,right(t),mid + 1,nr));
}
void apply() {
    while(!re.empty()) {
        auto now = re.front();re.pop();
        int d = now.first;
        int v = now.second;
        f.at(d) = max(f.at(d),v);
        do {
            d = d >> 1;
            f.at(d) = max(f.at(left(d)),f.at(right(d)));
        } while(d != 0);
    }
    return;
}
#undef left(i)
#undef right(i)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(3));
    for(int i = 0;i<n;i++) {
        cin>>f[i][0]>>f[i][1]>>f[i][2];
        sort(f[i].begin(),f[i].end());
    }
    sort(f.rbegin(),f.rend());

    ::n = offline(f);
    ::f.resize(::n << 2);

    // debug(f);

    bool c = 0;
    int last = -1;
    for(auto &i : f) {
        if(i[0] != last) {
            last = i[0];
            apply();
            // cerr<<"ok";
        }
        add(i[1],i[2]);
        if(check(i[1] + 1,::n - 1) > i[2]) {
            c = 1;
            break;
        }
        // debug(check(i[1] + 1,::n - 1),i[2]);
    }
    puts((c ? "Yes" : "No"));
    return 0;
}