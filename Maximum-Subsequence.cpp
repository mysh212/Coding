// Author : ysh
// 12/07/2022 Wed 20:50:01.93
// https://codeforces.com/contest/888/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int ck(int l,int r,vector<int>&f) {
    if(l == r) return f.at(l);
    int mid = (l + r) >> 1;
    int ll = ck(l,mid,f);
    int rr = ck(mid + 1,r,f);
    set<int,greater<int>>s;
    int last = 0;
    int mmax = max(ll,rr);
    if(mmax == b - 1) return mmax;
    for(int i = mid + 1;i<=r;i++) {
        last += f.at(i);
        last = last % b;
        s.insert(last);
    }
    last = 0;
    for(int i = mid;i>=l;i--) {
        last += f.at(i);
        last = last % b;
        int now = last;
        auto found = s.upper_bound(b - now);
        if(found == s.end()) continue;
        else mmax = max(mmax,last + *found);
    }
    return mmax;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        i = i % b;
    }
    cout<<ck(0,a - 1,f);
    return 0;
}