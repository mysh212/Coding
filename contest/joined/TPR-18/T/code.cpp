// Author : ysh
// 04/17/2022 Sun 16:17:34.66
#include<bits/stdc++.h>
#include<iomanip>
#define int long long
using namespace std;
signed main() {
    freopen("0.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int c[n][2] = {};
    for(int j = 0;j<2;j++) {
        for(int i = 0;i<n;i++) {
            cin>>c[i][j];
        }
    }
    int up = 0;
    for(int i = 0;i<n;i++) {
        up += c[i][0] * c[i][1];
    }
    int down[2] = {};
    for(int j = 0;j<2;j++) {
        int a = 0;
        for(int i = 0;i<n;i++) {
            // cerr<<a<<" ";
            a += c[i][j] * c[i][j];
        }
        down[j] = a;
    }
    // cerr<<"\n"<<up<<"\n"<<down;
    double ans = (int) (up * 100/sqrt(down[0] * down[1]));
    ans = ans / 100.0;
    printf("%.2f",ans);
    return 0;
}