// Author : ysh
// 04/22/2022 Fri 21:25:52.89
#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
// #define int long long
int c[101][MAX] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    vector<int>w(n);
    vector<int>v(n);
    for(int &i : w) {
        cin>>i;
    }
    for(int &i : v) {
        cin>>i;
    }
    for(int i = w[0];i<=k;i++) {
        c[0][i] = v[0];
    }
    for(int i = 1;i<n;i++) {
        for(int j = 1;j<=k;j++) {
            if(j - w[i] > 0) c[i][j] = max(c[i - 1][j],c[i - 1][j - w[i]] + v[i]);
            else c[i][j] = c[i - 1][j];
        }
    }
    cout<<c[n - 1][k];
    return 0;
}