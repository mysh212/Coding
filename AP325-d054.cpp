// Author : ysh
// 07/30/2022 Sat 14:10:11.62
// https://judge.tcirc.tw/ShowProblem?problemid=d054
// RE
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
            now = now - i;
            t = t + 1;
        }
    }
    return t;
}
int cp(int a,int b) {
    int l = check(a);
    return l > b;
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
    vector<int>v(sig);
    iota(v.begin(),v.end(),0);
    cout<<*lower_bound(v.begin(),v.end(),b,cp);
    return 0;
}