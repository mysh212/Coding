// Author : ysh
// 12/07/2022 Wed 11:40:15.38
// https://codeforces.com/contest/1674/problem/E
#include<bits/stdc++.h>
using namespace std;
inline int ck(int l,int r,vector<int>&f) {
    if(l + 1 == r) {
        
    }
    int mid = (l + r) >> 1;
    int ll = ck(l,mid,f);
    int rr = ck(mid + 1,r,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    cout<<ck(0,n - 1,f);
    return 0;
}