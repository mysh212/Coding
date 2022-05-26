// Author : 
// 05/04/2022 Wed 13:56:59.77
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

long long a[N], dp[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i ^ 1] + a[i], 0LL);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}