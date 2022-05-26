// Author : ysh
// 04/17/2022 Sun 15:01:12.65
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    int t = b / (a << 1);
    b = b % (a << 1);
    int ans = 0;
    if(c <= b) ans = t + 1;
    else ans = t;
    if(((a<<1) + 1) - c <= b) ans = ans + (t + 1);
    else ans = ans + t;
    cout<<ans;
    return 0;
}