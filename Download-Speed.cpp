// Author : ysh
// 02/28/2023 Tue 15:47:23.72
// https://cses.fi/problemset/task/1694
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
#define INT_MAX __LONG_LONG_MAX__
vector<int>v;
void walk(vector<vector<int>>&f,int x,int level = 0) {
    int n = f.size();
    queue<pair<int,int>>q;
    q.emplace(x,1);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int d = now.first;
        int l = now.second;
        if(v.at(d) != 0) continue;
        v.at(d) = l;
        for(int i = 0;i<n;i++) {
            if(f[d][i] != 0) q.emplace(i,l + 1);
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a,vector<int>(a));
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f[a][b] += c;
    }

    vector<bool>mark(a);
    int ans = 0;
    function<int(int,int,int,int)> check = [&] (int last,int x,int mmin,int now) {
        if(x == a - 1) return ans = ans + (mmin = (min(now,mmin))),mmin;
        if(mark.at(x)) return 0LL;
        int sig = 0;
        for(int i = 0;i<a;i++) {
            if(f[x][i] == 0 || v.at(i) <= v.at(x)) continue;
            int tmp = check(x,i,min(now,mmin),f[x][i]);
            sig = sig + tmp;
            now = now - tmp;
            f[x][i] = f[x][i] - tmp;
            f[i][x] = f[i][x] + tmp;
        }
        return sig;
    };

    for(int i = ans;;i = ans) {
        v = vector<int>(a);
        walk(f,0);
        check(-1,0,INT_MAX,INT_MAX);
        debug(v);
        if(i == ans) break;
    }
    // for(int i = 0;i<a;i++) {
    //     for(auto &j : f.at(i)) {
    //         cerr<<i<<" "<<j.first<<" "<<j.second<<"\n";
    //     }
    // }
    cout<<ans;
    return 0;
}