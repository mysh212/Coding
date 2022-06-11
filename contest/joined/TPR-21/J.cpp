// Author : ysh
// 05/31/2022 Tue  8:22:05.67
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    vector<int>f(a);
    cin>>f[0];
    int g = f[0];
    for(int i = 1;i<a;i++) {
        cin>>f[i];
        g = __gcd(g,f[i]);
    }
    // for(int i = 0;i<a;i++) {
    //     g = g * (f[i] / g);
    // }
    cin>>a;
    int tmp;
    for(int i = 0;i<a;i++) {
        cin>>tmp;
        if((tmp - 1115) % g == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    // cout<<g<<"\n";
    return 0;
}