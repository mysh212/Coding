// Author : ysh
// 06/09/2022 Thu 11:10:36.27
#include<bits/stdc++.h>
using namespace std;
int check(int,int);
#define MAX 51
int mark[MAX][MAX];
vector<int>f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    // int ff;cin>>ff;
    for(int &i : f) {
        cin>>i;
    }
    // int l;cin>>l;
    cout<<check(0,n - 1);
    return 0;
}
int check(int l,int r) {
    if(l == r) {
        mark[l][r] = f[l];
        return f[l];
    }
    int mmin = INT_MAX;
    
}