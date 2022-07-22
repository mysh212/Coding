// Author : ysh
// 07/21/2022 Thu  8:49:51.73
// https://judge.tcirc.tw/ShowProblem?problemid=d086
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
vector<vector<int>>mark;
vector<int>f;
int n;
int check(int,int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f.resize(n + 1);
    for(int &i : f) {
        cin>>i;
    }
    mark.resize(n + 1,vector<int>(n + 1,LONG_LONG_MAX));
    for(int i = 1;i<=n - 1;i++) {
        mark[i][i] = 0;
        mark[i][i + 1] = 0;
    }
    cout<<check(0,n);
    return 0;
}
int check(int l = 0,int r = n) {
    if(l == r || l + 1 == r) return 0;
    if(mark[l][r] != LONG_LONG_MAX) return mark[l][r];
    for(int i = l + 1;i<r;i++) {
        mark[l][r] = min(mark[l][r],check(l,i) + check(i,r) + (f[l] * f[i] * f[r]));
    }
    return mark[l][r];
}