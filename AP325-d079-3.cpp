// Author : ysh
// 06/09/2022 Thu 21:24:21.96
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>f;
int check(int,int);
int a,b;
const int MAX = (int) 1e6 + 5;
map<pair<int,int>,int>mark;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a);
    for(int &i : f) {
        cin>>i;
    }
    cout<<check(0,b);
    return 0;
}
int check(int l,int r) {
    // debug(l,r);
    int now = upper_bound(f.begin(),f.end(),l) - f.begin();
    // debug(now);
    assert(l <= r);
    int mmin = INT_MAX;
    bool c = 1;
    for(int j = now;;j++) {
        c = 0;
        if(j >= a || f[j] >= r) break;
        // mmin = min(mmin,check(l,j) + check(j + 1,r));
        int aa,bb;
        // debug(j);
        // assert(j < a);
        debug(mark[{l,f[j]}]);
        if(mark[{l,f[j]}] != 0) aa = mark[{l,f[j]}];
        else aa = mark[{l,f[j]}] = check(l,f[j]);
        if(mark[{f[j],r}] != 0) bb = mark[{f[j],r}];
        else bb = mark[{f[j],r}] = check(f[j],r);
        mmin = min(mmin,aa + bb);
    }
    debug((int) c,l,r,mmin + (r - l));
    if(c) return 0;
    if(mmin == INT_MAX) return 0;
    return mmin + (r - l);
}