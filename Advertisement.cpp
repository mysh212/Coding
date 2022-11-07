// Author : ysh
// 10/26/2022 Wed 12:49:50.23
// https://cses.fi/problemset/task/1142/
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
#define int long long
int check(int l,int r) {
    if(l == r) return f.at(l);
    int mid = (l + r) >> 1;
    int ll = check(l,mid);
    int rr = check(mid + 1,r);
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(signed &i : f) {
        cin>>i;
    }
    int mmax = 0;
    for(int i = 0;i<n;i++) {
        int mmin = f.at(i);
        for(int j = i;j<n;j++) {
            mmin = min(f.at(j),mmin);
            mmax = max(mmax,mmin * (j - i + 1));
        }
    }
    cout<<mmax;
    return 0;
}