// Author : ysh
// 08/25/2022 Thu  9:53:41.31
// https://cses.fi/problemset/task/1673
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int R = 1e13;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a,vector<int>(a,-R));
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a - 1][b - 1] = c;
    }
    for(int i = 0;i<a;i++) {
        f[i][i] = 0;
    }
    for(int k = 0;k<a;k++) {
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<a;j++) {
                f[i][j] = max(f[i][k],f[k][j]);
            }
    for(auto i : f) {
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
        }
    }
    cout<<f[0][a - 1];
}