// Author : ysh
// 04/09/2023 Sun 15:04:18.74
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int a,b;cin>>a>>b;
    // vector<int>f(a);
    // for(int &i : f) {
    //     cin>>i;
    // }
    // // tree<int>t(f);
    // while(b--) {
    //     int a,b,c;cin>>a>>b>>c;
    //     int ans = 0;
    //     for(int i = a - 1;i<=(b - 1);i++) {
    //         if(f.at(i) > c) {
    //             ans = ans + (f.at(i) << 1);
    //         }
    //         if(f.at(i) < c) {
    //             ans = ans + (c << 1);
    //         }
    //     }
    //     // cout<<ans<<" ";
    //     cout<<ans<<"\n";
    // }
    // return 0;
    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    for(auto &i : f) {
        for(int &j : i) {
            cin>>j;
        }
    }
    vector<seg_tree<int>>v;
    for(int i = 0;i<n;i++) {
        v.push_back(seg_tree<int>(f.at(i)));
    }
    seg_tree<seg_tree<int>>t(v);
    // int a,b,c,d;
    // while(cin>>a>>b>>c>>d) {
    //     a--;b--;c--;d--;
    //     cerr<<t.sum(a,c).sum(b,d)<<"\n";
    // }
    return 0;
}