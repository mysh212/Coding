// Author : ysh
// 05/21/2022 Sat  9:57:56.03
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<int>f(n);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2;i<n;i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        cout<<f.at(n - 1)<<"\n";
    }
    return 0;
}