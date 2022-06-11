// Author : ysh
// 06/10/2022 Fri 17:17:00.16
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
int a,b,c;
int sig(int x) {
    return ((x + 1) * x) >> 1;
}
int sigt(int x) {
    return ((((x - 1) << 1) + 1 + 1) * x) >> 1;
}
int check(int l,int r) {
    if(l + 1 == r) return l;
    // debug(l,r);
    int mid = (l + r) >> 1;
    // if(mid == l) return r;
    int s = sigt(mid);
    debug(mid,s);
    if(c + mid - 1 > a) {
        debug(c,mid,a);
        debug(c + mid - a - 1);
        debug(sig(c + mid - a - 1));
        s = s - sig(c + mid - a - 1);
    }
    if(c - mid + 1 <= 0) s = s - sig(mid - c);
    debug(s);
    if(s > b) return check(l,mid);
    else return check(mid,r);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        cin>>a>>b>>c;
        b = b - a;
        cout<<check(0,b + 10) + 1<<"\n";
        // vector<int>f(b - a + 1);
        // iota(f.begin(),f.end(),0);
        // cout<<*lower_bound(f.begin(),f.end(),1,cp);
        // b = b - a;
        // int l,r;l=r=c;
        // for(int i = 1;;i++) {
        //     if(i == 1) {
        //         b = b - 1;
        //         if(b < 0) cout<<i - 1;
        //         continue;
        //     }
        //     if(l > 1) l--;
        //     if(r < a) r++;
        //     // printf("%d\n",r - l + 1);
        //     b = b - (r - l + 1);
        //     if(b < 0) {
        //         cout<<(i - 1) + 1<<"\n";
        //         break;
        //     }
        // }
    }
    return 0;
}