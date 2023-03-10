// Author : ysh
// 03/10/2023 Fri 14:13:57.62
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b) {
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return gcd(b,a % b);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}