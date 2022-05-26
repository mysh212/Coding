// Author : ysh
// 04/22/2022 Fri 20:33:58.37
#include<bits/stdc++.h>
using namespace std;
int c[2000][2000] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>c[i][j];
        }
    }
    for(int i = 0;i<a;i++) {
        for(int j = (i == 0 ? 1 : 0);j<b;j++) {
            // cout<<j;
            if(i == 0) {
                c[i][j] += c[i][j - 1];
                continue;
            }
            if(j == 0) {
                c[i][j] += c[i - 1][j];
                continue;
            }
            c[i][j] = c[i][j] + max(c[i][j - 1],c[i - 1][j]);
        }
    }
    cout<<c[a - 1][b - 1];
    return 0;
}