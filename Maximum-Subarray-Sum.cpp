// Author : ysh
// 2025/03/31 Mon 11:51:22
// https://cses.fi/problemset/task/1643
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    int last = 0;
    int mmin = 0, ans = INT_MIN;
    for(int &i : f) {
        i = last += i;

        ans = max(ans, i - mmin);
        mmin = min(i, mmin);
    }

    cout<<ans;
    return 0;
}