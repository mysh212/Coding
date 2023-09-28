// Author : ysh
// 2023/07/10 Mon 20:01:17
// https://codeforces.com/contest/1475/problem/F
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<bool>>f(n,vector<bool>(n)),g;
        vector<bool>h(n),v(n),hh(n),vv(n);
        g = f;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char tmp;cin>>tmp;
                f[i][j] = (tmp == '1');
            }
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char tmp;cin>>tmp;
                g[i][j] = (tmp == '1');
            }
        }

        
        bool c = f[0][0],d = g[0][0];
        for(int i = 0;i<n;i++) {
            h[i] = f[0][i] xor c;
            hh[i] = g[0][i] xor d;
            if(f[i][0]) v[i] = 1;
            if(g[i][0]) vv[i] = 1;
            f[i][0] = f[0][i] = g[i][0] = g[0][i] = 0;
        }

        for(int i = 1;i<n;i++) {
            for(int j = 1;j<n;j++) {
                f[i][j] = f[i][j] xor v[i] xor h[j];
                g[i][j] = g[i][j] xor vv[i] xor hh[j];
            }
        }
        cout<<(f == g ? "YES\n" : "NO\n");
    }
    return 0;
}