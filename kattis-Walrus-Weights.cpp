// Author : ysh
// 04/06/2022 Wed 17:48:02.14
// https://open.kattis.com/problems/walrusweights
#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("0.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int c[n + 1][2001] = {};
    for(int i = 1;i<=2000;i++) {
        if(i >= a[0]) c[1][i] = a[0];
    }
    for(int i = 2;i<=n;i++) {
        for(int j = 1;j<=2000;j++) {
            if(j - a[i - 1] >= 0 && c[i - 1][j - a[i - 1]] + a[i - 1] <= j) c[i][j] = max(max(c[i - 1][j],c[i][j - 1]),c[i - 1][j - a[i - 1]] + a[i - 1]);
            else c[i][j] = max(c[i][j],c[i][j - 1]);
        }
    }
    // for(int j = 1;j<=n;j++) {
    //     for(int i = 1;i<=2000;i = i + 100) {
    //         cerr<<c[j][i]<<" ";
    //     }
    //     cerr<<"\n";
    // }
    int mmax = 0;
    int dt = 1000;
    for(int i = 1000;i<=2000;i++) {
        if(abs(1000 - c[n][i]) <= dt) {
            mmax = c[n][i];
            dt = abs(1000 - c[n][i]);
        }
        if(c[n][i] >= 1000) break;
    }
    cout<<mmax;
    return 0;
}