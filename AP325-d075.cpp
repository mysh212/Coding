// Author : ysh
// 07/26/2022 Tue 13:54:21.92
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a + 1,vector<int>(b - c + 1));
    int sig = 0;
    for(int i = 1;i<=a;i++) {
        int tmp;cin>>tmp;
        sig = sig + tmp;
        // if(tmp > b - c) continue;
        for(int j = 1;j<=b - c;j++) {
            if(j >= tmp) f[i][j] = max(f[i - 1][j],f[i - 1][j - tmp] + tmp);
            else f[i][j] = f[i - 1][j];
        }
    }
    // for(vector<int> j : f) {
    //     for(int i : j) {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<sig - f[a][b - c];
    return 0;
}