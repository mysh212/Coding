// Author : ysh
// 12/12/2022 Mon 12:32:12.28
// https://tioj.ck.tp.edu.tw/problems/2256
#include<bits/stdc++.h>
using namespace std;
int n,t,ll;
bool check(int gap,vector<int>&f) {
    int l = 0;
    int r = 1;
    int ans = 0;
    while(r < n) {
        if(abs(f.at(r) - f.at(r - 1)) <= gap) {
            r++;
        } else {
            l = r;
            r++;
            continue;
        }
        if(r - l >= ll) {
            ans++;
            l = r;
            r++;
        }
    }
    return (ans >= t ? 1 : 0);
}
int ck(int l,int r,vector<int>&f) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    return ck(mid + 1,r,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>ll>>t;
    vector<int>f(n);
    int mmax = 0;
    for(int &i : f) {
        cin>>i;
        mmax = max(mmax,i);
    }
    sort(f.begin(),f.end());
    cout<<ck(0,mmax,f);
    return 0;
}