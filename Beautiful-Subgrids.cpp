// Author : ysh
// 02/25/2023 Sat  6:37:38.90
// https://cses.fi/problemset/task/2137
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int a) {
    return (a * (a - 1)) >> 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bitset<3000>s[n];
    for(int i = 0;i<n;i++) {
        cin>>s[i];
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i + 1;j < n;j++) {
            ans = ans + check((s[i] & s[j]).count());
        }
    }
    cout<<ans;
    return 0;
}