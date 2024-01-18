// Author : ysh
// 2024/01/03 Wed 22:09:19
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
    if(b == 0) return a;
    return gcd(b,a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}