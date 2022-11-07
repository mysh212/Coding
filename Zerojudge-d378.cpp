// Author : ysh
// 10/31/2022 Mon 21:57:29.57
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    int t = 0;
    while(cin>>a>>b) {
        cout<<"Case #"<<++t<<" :\n";
        vector<vector<int>>f(a + 1,vector<int>(b + 1));
        for(int i = 1;i<=a;i++) {
            for(int j = 1;j<=b;j++) {
                cin>>f.at(i).at(j);
            }
        }
        for(int i = 1;i<=a;i++) {
            for(int j = 1;j<=b;j++) {
                if(i == 1) f[i][j] = f[i][j - 1] + f[i][j];
                if(j == 1) f[i][j] = f[i - 1][j] + f[i][j];
                f[i][j] = min(f[i - 1][j],f[i][j - 1]) + f[i][j];
            }
        }
        cout<<f[a][b]<<"\n";
    }
    return 0;
}