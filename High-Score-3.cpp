// Author : ysh
// 08/26/2022 Fri 18:43:20.27
// https://cses.fi/problemset/task/1673
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a,vector<int>(a,INT_MIN));
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f[a][b] = c;
        // f[b][a] = c;
    }
    for(int i = 0;i<a;i++) {
        f[i][i] = 0;
    }
    for(int k = 0;k<a;k++) {
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<a;j++) {
                if(i == j) continue;
                f[i][j] = max(f[i][j],f[i][k] + f[k][j]);
            }
        }
    }
    int r = f[0][a - 1];
    for(int k = 0;k<a;k++) {
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<a;j++) {
                if(i == j) continue;
                f[i][j] = max(f[i][j],f[i][k] + f[k][j]);
            }
        }
    }
    if(r != f[0][a - 1]) cout<<"-1\n";
    else cout<<r<<"\n";
    return 0;
}