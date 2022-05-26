// Author : ysh
// 04/17/2022 Sun 16:17:34.66
//WA
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int main() {
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
    int down = 1;
    for(int j = 0;j<2;j++) {
        int a = 0;
        for(int i = 0;i<n;i++) {
            // cerr<<a<<" ";
            a += c[i][j] * c[i][j];
        }
        down *= a;
    }
    // cerr<<"\n"<<up<<"\n"<<down;
    cout<<fixed<<setprecision(2)<<((int) ((up / sqrt(down)) * 100)) / 100.0;
    return 0;
}