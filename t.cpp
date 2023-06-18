// Author : ysh
// 06/07/2023 Wed 21:23:10.83
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
inline bool check(vector<int>&f,int x) {
    return ((int) (upper_bound(f.begin(),f.end(),c + x) - lower_bound(f.begin(),f.end(),c - x))) >= b;
}
int ck(vector<int>&f,int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(f,mid)) return ck(f,l,mid);
    return ck(f,mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    vector<int>f(a);
    for(int &i : f) cin>>i;
    sort(f.begin(),f.end());

    cout<<ck(f,0,(int) 2e9);
    return 0;
}