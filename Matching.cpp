// Author : ysh
// 12/09/2022 Fri  9:59:33.48
// https://atcoder.jp/contests/dp/tasks/dp_o
#include<bits/stdc++.h>
using namespace std;
constexpr int R = (int) 1e9 + 7;
#define int long long
int g[1 << 21] = {};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bool c[n][n] = {};
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            // cin>>c[i][j];
            int tmp;cin>>tmp;
            if(tmp == 1) c[i][j] = 1;
        }
    }
    g[0] = 1;
    for(int i = 0,len = (1 << n);i<len;i++) {
        int ct = __builtin_popcount(i);
        int t = i;
        for(int j = 0;j<n;j++) {
            if(!(t & 1)) {
                if(c[j][ct]) {
                    g[i | (1 << j)] += g[i];
                    g[i | (1 << j)] = g[i | (1 << j)] % R;
                }
            }
            t = t >> 1;
        }
    }
    // for(int i = 0,len = (1 << n);i<len;i++) cout<<g[i]<<" ";
    cout<<g[(1 << n) - 1];
    return 0;
}