// Author : ysh
// 2023/07/07 Fri 23:02:20
#include<bits/stdc++.h>
using namespace std;
// #define int double
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;double b,c;cin>>a>>b>>c;
        vector<int>f(a);
        for(int &i : f) cin>>i;
        sort(f.begin(),f.end());

        double ans = 0;
        for(int i = 0;i<a - 1;i++) {
            double tmp = (b / c) * (c - abs(f.at(i) - f.at(i + 1)));
            tmp = max(tmp,0.0);
            // cout<<tmp<<" ";
            ans = ans + (((b + tmp) * min(abs(f.at(i) * 1.0 - f.at(i + 1)) * 1.0,c)));
        }
        ans = ans + ((b * c));
        cout<<fixed<<setprecision(10)<<ans / 2<<"\n";
    }
    return 0;
}