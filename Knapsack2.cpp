// Author : ysh
// 06/10/2022 Fri 14:09:54.16
// https://atcoder.jp/contests/dp/tasks/dp_e
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX LONG_LONG_MAX
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,ww;cin>>n>>ww;
    vector<int>v(n),w(n);
    for(int i = 0;i<n;i++) {
        cin>>w[i]>>v[i];
    }
    vector<int>f(100005,INT_MAX);
    f[0] = 0;
    for(int j = 0;j<n;j++) {
        for(int i = 100004;i >= 0;i--) {
            if(f[i] == INT_MAX) continue;
            if(i + v[j] < 100005) {
                f[i + v[j]] = min(f[i + v[j]],f[i] + w[j]);
                // break;
            }
        }
    }
    // for(int i = 0;i<100005;i++) {
    //     if(f[i] != INT_MAX) {
    //         cerr<<i<<" "<<f[i]<<"\n";
    //     }
    // }
    for(int i = 100004;i >= 0;i--) {
        if(f[i] != INT_MAX && f[i] <= ww) {
            cout<<i;
            return 0;
        }
    }
    return -1;
}