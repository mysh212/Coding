// Author : ysh
// 2023/06/21 Wed 07:13:24
// https://codeforces.com/contest/1843/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int ans = 0;
        bool neg = 0;
        vector<int>f(n);
        for(int &i : f) cin>>i,ans = ans + abs(i);

        int o = 0;
        for(int i : f) {
            if(i < 0 && neg) continue;
            if(i == 0 && neg) continue;
            if(i > 0 && neg) neg = 0,o++;
            if(i > 0 && !neg) continue;
            if(i == 0 && !neg) continue;
            if(i < 0 && !neg) neg = 1;
        }
        if(neg) o++;
        cout<<ans<<" "<<o<<"\n";
    }
    return 0;
}