// Author : ysh
// 10/29/2022 Sat 17:52:05.39
// https://codeforces.com/contest/1740/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        int mmaxl,mmaxr,l,r;mmaxl = mmaxr = l = r = 0;
        for(int i = 0;i<m;i++) {
            int a,b;cin>>a>>b;
            if(a > b) swap(a,b);
            mmaxl = max(mmaxl,a);
            mmaxr = max(mmaxr,b);
            l += a;
            r += b;
        }
        cout<<min((l + mmaxr) << 1,(r + mmaxl) << 1)<<"\n";
    }
    return 0;
}