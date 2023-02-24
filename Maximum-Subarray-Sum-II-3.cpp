// Author : ysh
// 02/24/2023 Fri  9:04:46.70
// https://cses.fi/problemset/task/1644
#include<bits/stdc++.h>
using namespace std;
#define c(i,j) min(i,j)
#include<table>
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<int>f(a);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
        // i = i + (int) 1e15;
    }
    table<int>t(f);
    int mmax = LLONG_MIN;
    debug(f,t.get(1,2));
    for(int i = 0;i<a;i++) {
        int l = i - (c);
        int r = i - (b);
        if(r >= -1 && l <= -1) mmax = max(mmax,f.at(i));
        if(l < 0 && r < 0) continue;
        l = max(0LL,l);
        r = max(0LL,r);
        debug(i,l,r);
        mmax = max(mmax,f.at(i) - t.get(l,r));
        // cout<<mmax<<" ";
    }
    cout<<mmax;
    return 0;
}