// Author : ysh
// 05/06/2022 Fri 11:14:37.61
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    vector<int>f(n + 1),g(n + 1);
    vector<int>aa(n + 1),bb(n + 1);
    f[0] = g[0] = k;
    for(int i = 1;i<=n;i++) {
        cin>>f[i]>>g[i];
    }
    for(int i = 1;i<=n;i++) {
        aa[i] = min(aa[i - 1] + abs(f[i - 1] - f[i]),bb[i - 1] + abs(g[i - 1] - f[i]));
        bb[i] = min(aa[i - 1] + abs(f[i - 1] - g[i]),bb[i - 1] + abs(g[i - 1] - g[i]));
    }
    cout<<min(aa[n],bb[n]);
    return 0;
}