// Author : ysh
// 09/02/2022 Fri 19:10:54.51
#include<bits/stdc++.h>
using namespace std;
#define R 100000007
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int c[n + 1][2][3] = {};
    c[1][0][0] = 1;
    c[1][1][0] = 1;
    c[1][0][1] = 1;
    for(int i = 2;i<=n;i++) {
        for(int j = 0;j <= 1;j++) {
            for(int k = 0;k <= 2;k++) {
                if(j + k > i) continue;
                int tmp = 0;
                if(k == 0) {
                    tmp += c[i - 1][j][1] + c[i - 1][j][2];
                }
                if(j >= 1) tmp += c[i - 1][j - 1][k];
                if(k >= 1) tmp += c[i - 1][j][k - 1];
                c[i][j][k] = (tmp);
            }
        }
    }
    for(int i = 0;i<=1;i++) {
        for(int j = 0;j<=2;j++) {
            cout<<c[2][i][j]<<" ";
        }
        cout<<"\n";
    }
    int ans = 0;
    for(int i = 0;i <= 1;i++) {
        for(int j = 0;j <= 2;j++) {
            ans += c[n][i][j];
        }
    }
    cout<<ans;
    return 0;
}