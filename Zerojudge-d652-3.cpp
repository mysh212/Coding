// Author : ysh
// 08/19/2022 Fri 19:15:54.69
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<vector<int>>mark;
int check(int l,int r) {
    if(mark[l][r] != -1) return mark[l][r];
    if(l + 1 == r) return 0;
    int mmin = INT_MAX;
    for(int i = l + 1;i<r;i++) {
        mmin = min(mmin,check(l,i) + check(i,r) + f[l] * f[i] * f[r]);
    }
    return mark[l][r] = mmin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    mark.resize(n,vector<int>(n,-1));
    for(int &i : f) {
        cin>>i;
    }
    cout<<check(0,n - 1);
    return 0;
}