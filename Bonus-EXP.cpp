// Author : ysh
// 2024/09/08 Sun 20:27:40
// https://atcoder.jp/contests/abc369/tasks/abc369_d
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    vector<vector<int>>v(n,vector<int>(2));
    v.at(0).at(1) = f.at(0);
    for(int i = 1;i<n;i++) {
        v.at(i).at(0) = max(v.at(i - 1).at(1) + (f.at(i) << 1),v.at(i - 1).at(0));
        v.at(i).at(1) = max(v.at(i - 1).at(0) + f.at(i),v.at(i - 1).at(1));
    }

    cout<<max(v.at(n - 1).at(0),v.at(n - 1).at(1));
    return 0;
}