// Author : ysh
// 2023/08/22 Tue 17:08:18
// https://codeforces.com/problemset/problem/1857/F
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// #include<fast>
#define int int64_t
int ck(int64_t x,int l = 1,int r = 2e9) {
    // debug(x,l,r);
    if(x == 0) return 0;
    if(x < 0) return -1;
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(1LL * mid * mid <= x) return ck(x,mid,r);
    else return ck(x,l,mid);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        gp_hash_table<int,int>s;
        while(n--) {
            int tmp;cin>>tmp;
            s[tmp]++;
        }

        int m;cin>>m;
        while(m--) {
            int64_t a,b;cin>>a>>b;
            int64_t tmp = a * a - (b * 4);
            double t = ck(tmp);
            debug(tmp,t);
            if(tmp < 0 || pow(int(t),2) != tmp) cout<<"0 ";
            else if(tmp == 0) {
                int r = s[a / 2];
                cout<<((r  * 1LL * (r - 1)) >> 1)<<" ";
            } else {
                int l = (a - int(t)) / 2;
                int r = (a + int(t)) / 2;
                debug(l,r);
                cout<<1LL * s[l] * s[r]<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}