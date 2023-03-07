// Author : ysh
// 03/01/2023 Wed 11:03:34.93
// https://cses.fi/problemset/task/1694/
// NF
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>v;
void walk(vector<vector<int>>&f,int x,int level = 0) {
    int n = f.size();
    queue<pair<int,int>>q;
    q.emplace(0,1);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int d = now.first;
        int l = now.second;
        if(v.at(d) != 0) continue;
        v.at(d) = l;
        for(int i = 0;i<n;i++) {
            if(f[x][i] != 0) q.emplace(f[x][i],l + 1);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a,vector<int>(a));
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f[a][b] = f[a][b] + c;
    }

    long long ans = 0;
    vector<bool>mark(a);
    function<int(int,int,int,int)> check = [&] (int last,int x,int mmin,int now) {
        debug(x,mark);
        if(x == a - 1) return ans = ans + (mmin = (min(now,mmin))),mmin;
        if(mark.at(x)) return 0;
        int sig = 0;
        for(int i = 0;i<a;i++) {
            if(f[x][i] == 0 || v.at(i) < v.at(x)) continue;
            int tmp = check(x,i,min(now,mmin),f[x][i]);
            now = now - tmp;
            f[x][i] = f[x][i] - tmp;
            if(i != a - 1) f[i][x] = f[i][x] + tmp;
            sig = sig + tmp;
            if(tmp == 0) mark.at(i) = 1;
        }
        return sig;
    };

    v.resize(a);
    walk(f,0);
    check(-1,0,INT_MAX,INT_MAX);
    cout<<ans;
    return 0;
}