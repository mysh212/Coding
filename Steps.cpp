// Author : ysh
// 2023/09/13 Wed 12:49:53
// https://codeforces.com/problemset/problem/152/B
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int x,y;cin>>x>>y;
    int m;cin>>m;
    int ans = 0;
    while(m--) {
        int xx,yy;cin>>xx>>yy;
        int tx,ty;
        if(xx > 0) tx = (a - x) / xx;
        else if(xx < 0) tx = (1 - x) / xx;
        else tx = LLONG_MAX;
        if(yy > 0) ty = (b - y) / yy;
        else if(yy < 0) ty = (1 - y) / yy;
        else ty = LLONG_MAX;
        x = x + (xx * min(tx,ty));
        y = y + (yy * min(tx,ty));
        ans = ans + min(tx,ty);
        // debug(tx,ty,x,y,ans);
    }
    cout<<ans;
    return 0;
}