// Author : gamic
// 2023/07/28 Fri 14:40:31
#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    a.push_back(0);
    a.push_back(l + 1);
    sort(begin(a), end(a));
    int ans = 0;
    for(int i = 0; i < a.size() - 1; ++i){
        ans += (a[i + 1] - a[i] - 1) / 15;
    }

    cout << ans;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}