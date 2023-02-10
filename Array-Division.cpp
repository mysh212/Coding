// Author : ysh
// 01/28/2023 Sat 12:42:22.55
// https://cses.fi/problemset/task/1085
#include<bits/stdc++.h>
using namespace std;
int a,b,mmax;
#define int long long
bool check(int x,vector<int>&f) {
    if(mmax > x) return 0;
    int sig = 0;
    int c = 0;
    for(int &i : f) {
        if(c > b) break;
        if(sig + i > x) sig = 0,c++;
        sig = sig + i;
    }
    if(sig != 0) c++;
    return c <= b;
}
int ck(int l,int r,vector<int>&f) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    else return ck(mid + 1,r,f);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<int>f(a);
    int sig = 0;
    for(int &i : f) {
        cin>>i;
        sig = sig + i;
    }
    mmax = *max_element(f.begin(),f.end());
    // sort(f.rbegin(),f.rend());
    cout<<ck(0,sig,f);
    return 0;
}