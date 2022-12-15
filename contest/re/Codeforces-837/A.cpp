// Author : ysh
// 12/12/2022 Mon 15:35:25.96
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        if(f.at(n - 1) == f.at(0)) {
            cout<<n * (n - 1)<<"\n";
            continue;
        }
        int t = 1;
        for(int i = 1;i<n;i++) {
            if(f.at(i) == f.at(i - 1)) t++;
            else break;
        }
        int r = 1;
        for(int i = n - 2;i >= 0;i--) {
            if(f.at(i) == f.at(i + 1)) r++;
            else break;
        }
        // cerr<<t<<" "<<r<<"\n";
        cout<<((t * r) << 1)<<"\n";
    }
    return 0;
}