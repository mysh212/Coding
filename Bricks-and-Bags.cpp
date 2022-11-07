// Author : ysh
// 10/29/2022 Sat 18:49:43.90
// https://codeforces.com/contest/1740/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        int mmax,mmin,r;
        vector<int>f(m);
        for(int &i : f) {
            cin>>i;
        }
        int ans = 0;
        sort(f.begin(),f.end());
        ans = max((f.at(m - 1) << 1) - f.at(m - 2) - f.at(0),f.at(m - 1) + f.at(1) - (f.at(0) << 1));
        cout<<ans<<"\n";
    }
    return 0;
}