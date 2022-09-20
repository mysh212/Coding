// Author : ysh
// 09/19/2022 Mon 20:30:16.22
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int i = 0;i<n;i++) {
            string a;cin>>a;
            for(int j = 0;j<n;j++) {
                if(a[j] == '1') {
                    f[j] = i;
                }
            }
        }
        int ans = 0;
        int l,r;
        for(int i = 0;i<n;i++) {
            l = r = f[i];
            for(int j = i;j<n;j++) {
                l = min(l,f[j]);
                r = max(r,f[j]);
                if(r - l == j - i) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}