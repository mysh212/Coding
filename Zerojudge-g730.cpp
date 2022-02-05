// Author : ysh
// 01/07/2022 Fri 21:34:05.07
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a[2][2][2] = {};
    for(int i = 0;i<2;i++) {
        for(int j = 0;j<2;j++) {
            for(int k = 0;k<2;k++) {
                cin>>a[i][j][k];
                //printf("a[%d][%d][%d]=%d\n",i,j,k,a[i][j][k]);
            }
        }
    }
    for(int i = 0;i<2;i++) {
        for(int j = 0;j<2;j++) {
            if(a[i][0][j]>a[i][1][j]) swap(a[i][0][j],a[i][1][j]);
        }
    }
    int b,c;cin>>b>>c;
    if(b<a[1][1][0]&&b>a[1][0][0]&&c<a[1][1][1]&&c>a[1][0][1]) {
        cout<<0;
        return 0;
    }
    if(b<a[0][1][0]&&b>a[0][0][0]&&c<a[0][1][1]&&c>a[0][0][1]) {
        cout<<1;
        return 0;
    }
    cout<<2;
    return 0;
}