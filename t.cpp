// Author : ysh
// 11/22/2022 Tue 16:38:20.98
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;cin>>n;
    long long ans = 0;
    for(long long i = 1;i<=n;i++) {
        if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0) ans++;
    }
    cout<<n - ans;
    return 0;
}