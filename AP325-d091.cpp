// Author : ysh
// 07/28/2022 Thu 14:55:22.06
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>f;
vector<int>mark;
// int t = 0;
int ff(int x) {
    // printf("%d",x);
    if(mark[x] == x) return x;
    return mark[x] = ff(mark[x]);
}
void check(int x,int y) {
    mark[ff(x)] = ff(y);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    mark.resize(a);
    for(int &i : f) {
        cin>>i;
    }
    iota(mark.begin(),mark.end(),0);
    for(int i = 0;i<b;i++) {
        // for(int i : mark) cerr<<i<<" ";
        int a,b;cin>>a>>b;
        check(a,b);
    }
    vector<int>v(a);
    int mmax = INT_MIN;
    for(int i = 0;i<a;i++) {
        v[ff(i)] = v[ff(i)] + f[i];
        mmax = max(mmax,v[ff(i)]);
    }
    cout<<mmax;
    return 0;
}