// Author : ysh
// 07/30/2022 Sat 14:19:18.50
// https://judge.tcirc.tw/ShowProblem?problemid=d054
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>f;
int mmax;
int check(int x) {
    int t = 0;
    int now = x;
    if(x < mmax) return LONG_LONG_MAX;
    for(int i : f) {
        if((now -= i) < 0) {
            now = x - i;
            t = t + 1;
        }
    }
    return t;
}
int cp(int a,int b) {
    int l = check(a);
    return l > b;
}
int ff(int l,int r,int t) {
    // cerr<<l<<" "<<r<<"\n";
    assert(l <= r);
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(cp(mid,t)) {
        return ff(mid + 1,r,t);
    }
    return ff(l,mid,t);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int sig = 0;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        f.push_back(tmp);
        sig = sig + tmp;
    }
    mmax = *max_element(f.begin(),f.end());
    // vector<int>v(sig);
    // iota(v.begin(),v.end(),0);
    cout<<ff(0,sig,b);
    return 0;
}