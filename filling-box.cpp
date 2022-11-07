// Author : ysh
// 11/05/2022 Sat 14:10:09.03
// https://www.luogu.com.cn/problem/P1049
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r;cin>>r;
    int n;cin>>n;
    int f[2][20001] = {};
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        // f[i & 1][tmp] = tmp;
        int now = i & 1;e
        for(int j = 0;j<tmp;j++) f[now][j] = f[!(now)][j];
        for(int j = tmp;j <= r;j++) {
            f[now][j] = max(f[!(now)][j - tmp] + tmp,f[!(now)][j]);
        }
        // for(int j = 0;j<=r;j++) cout<<f[now][j]<<" ";
        // cerr<<"\n";
    }
    cout<<r - f[!(n & 1)][r];
    return 0;
}