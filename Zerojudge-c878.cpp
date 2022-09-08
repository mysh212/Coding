// Author : ysh
// 09/02/2022 Fri 19:10:54.51
#include<bits/stdc++.h>
using namespace std;
#define R 100000007
// struct box{
//     int x = 0;
//     void operator=(int x) {
//         this->x = x;
//     }
//     int operator+(box y) {
//         return (x + y.x) % R;
//     }
//     int operator+(box y) {
//         return x = (x + y.x) % R;
//     }
// };
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int c[2][2][3] = {};
    c[1][0][0] = 1;
    c[1][1][0] = 1;
    c[1][0][1] = 1;
    for(int i = 2;i<=n;i++) {
        c[i & 1][1][0] = c[!(i & 1)][0][1] + c[!(i & 1)][0][2] + c[!(i & 1)][0][0] + c[!(i & 1)][1][0] + c[!(i & 1)][1][1] + c[!(i & 1)][1][2];
        c[i & 1][0][0] = c[!(i & 1)][0][0] + c[!(i & 1)][0][1] + c[!(i & 1)][0][2];
        c[i & 1][0][1] = c[!(i & 1)][0][0];
        c[i & 1][1][1] = c[!(i & 1)][1][0];
        c[i & 1][0][2] = c[!(i & 1)][0][1];
        c[i & 1][1][2] = c[!(i & 1)][1][1];
        for(int j = 0;j<=1;j++) {
            for(int k = 0;k<=2;k++) {
                c[i & 1][j][k] = c[i & 1][j][k] % R;
            }
        }
    }
    // for(int i = 0;i<=1;i++) {
    //     for(int j = 0;j<=2;j++) {
    //         cout<<c[2][i][j] % R<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans = 0;
    for(int i = 0;i <= 1;i++) {
        for(int j = 0;j <= 2;j++) {
            ans += c[n & 1][i][j];
            // ans = ans % R;
        }
    }
    cout<<ans % R;
    return 0;
}