// Author : ysh
// 02/14/2022 Mon 13:06:32.40
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/J
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int n;cin>>n;
    int sig = 0,tmp,mmin = 0,ans = 0;
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        sig += tmp;
        ans = max(ans,sig - mmin);
        mmin = min(sig,mmin);
    }
    cout<<ans;
    return 0;
}