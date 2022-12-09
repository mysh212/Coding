// Author : ysh
// 12/09/2022 Fri  9:59:33.48
// https://atcoder.jp/contests/dp/tasks/dp_o
#include<bits/stdc++.h>
using namespace std;
int main() {
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
    int g[1 << n] = {};
    g[0] = 1;
    for(int i = 0,len = (1 << n);i<len;i++) {
        int ct = __builtin_popcount(i);
        int t = i;
        for(int j = 0;j<n;j++) {
            if(!(t & 1)) {
                t = t >> 1;
                if(c[j][ct + 1]) g[i | (1 << j)] += g[i];
            }
            t = t >> 1;
        }
    }
    cout<<g[(1 << n) - 1];
    return 0;
}