// Author : ysh
// 02/23/2023 Thu 14:02:52.86
// https://cses.fi/problemset/task/1140
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<array<int,3>>f(n);
    for(auto &i : f) cin>>i[0]>>i[1]>>i[2];
    sort(f.begin(),f.end(),[](array<int,3>&a,array<int,3>&b) {
        return a[1] < b[1];
    });
    vector<int>v(n);
    v.at(0) = f[0][2];
    for(int i = 1;i<n;i++) {
        // for(int i : v) cerr<<i<<" ";
        // cerr<<"\n";
        auto found = upper_bound(f.rbegin(),f.rend(),f.at(i)[0],[](int a,array<int,3>b) {
            return a > b[1];
        });
        if(found == f.rend()) v.at(i) = max(v[i - 1],f[i][2]);
        else v.at(i) = max(v.at(i - 1),v.at(f.rend() - found - 1) + f[i][2]);
    }
    cout<<*max_element(v.begin(),v.end());
    return 0;
}