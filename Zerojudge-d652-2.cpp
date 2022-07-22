// Author : ysh
// 07/21/2022 Thu 17:29:13.99
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    n--;
    vector<int>f(n + 1);
    for(int &i : f) {
        cin>>i;
    }
    vector<vector<int>>mark(n + 2,vector<int>(n + 2,INT_MAX));
    for(int i = 0;i<=n;i++) {
        mark[i][i] = 0;
        mark[i][i + 1] = 0;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 0;i + j<=n;j++) {
            for(int k = j;k < i + j;k++) {
                //cerr<<j<<" "<<j + i<<" "<<k<<"\n";
                if(mark[j][k] == INT_MAX || mark[k][j + i] == INT_MAX) continue;
                mark[j][j + i] = min(mark[j][j + i],mark[j][k] + mark[k][j + i] + (f[j] * f[k] * f[j + i]));
                // for(auto i : mark) {
                //     for(auto j : i) {
                //         cout<<j<<" ";
                //     }
                //     cout<<"\n";
                // }
                // cout<<"\n";
            }
        }
    }
    cout<<mark[0][n];
    return 0;
}