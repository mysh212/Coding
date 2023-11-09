// Author : ysh
// 2023/09/26 Tue 17:26:17
// https://codeforces.com/problemset/problem/1400/B
// WA
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

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        int x,y;cin>>x>>y;
        int xx,yy;cin>>xx>>yy;

        if(xx > yy) {
            swap(xx,yy);
            swap(x,y);
        }

        int mmax,ans;mmax = ans = 0;
        for(int i = 0;i<=x;i++) {
            if(xx * i > a) break;
            int now = i + min(((a - (xx * i)) / yy),y);
            if(now > mmax) {
                mmax = now;
                ans = i;
            }
        }

        x = x - ans;
        // cout<<ans<<" "<<min((a - (xx * ans)) / yy,y)<<"\t";
        y = y - (mmax - ans);
        debug(x,y);

        int aans = mmax;
        ans = mmax = 0;
        for(int i = 0;i<=x;i++) {
            debug(a,b,x,y,xx,yy);
            if(xx * i > b) break;
            int now = i + min(((b - (xx * i)) / yy),y);
            if(now > mmax) {
                mmax = now;
                ans = i;
            }
        }
        // cout<<ans<<" "<<min((b - (xx * ans)) / yy,y)<<"\n";

        debug(aans,mmax);
        cout<<aans + mmax<<" ";
    }
    return 0;
}