// Author : ysh
// 2026/10/29 Thu 19:31:48
#include<bits/stdc++.h>
#include <slow>
#define int long long
using namespace std;

static constexpr int mod = 998244353;
int n;
vector<int> f, fp;
vector<vector<int>> dp, cnt;

static int check(const int l, const int r) {
    if(l >= r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = check(l+1, r) * fp[cnt[l][r]] % mod;
    for(int m = l; m < r; m++) {
        int tmp = check(l+1, m) % mod;
        tmp = (tmp * fp[cnt[l][m]]) % mod;
        tmp = (tmp * check(m+1, r)) % mod;
        if(f[l] < f[m+1]) ans = (ans + tmp) % mod;
    }
    return dp[l][r] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f.resize(n);
    fp.resize(n+1);
    for(auto &x : f) cin >> x;
    dp.resize(n, vector<int> (n,-1));
    cnt.resize(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) dp[i][i] = 1, cnt[i][i] = 0;
    fp[0] = 1;
    for(int i = 1; i < n; i++) {
        fp[i] = (fp[i-1] * 2) % mod;
        for(int j = i+1; j < n; j++) {
            cnt[i][j] = cnt[i][j-1] + (f[i] < f[j]);
        }
    }
    fp[n] = (fp[n-1] * 2) % mod;
    // debug(cnt);
    // debug(fp);
    cout << check(1,n-1);
}