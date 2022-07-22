// Author : ysh
// 07/20/2022 Wed 19:43:31.70
// https://judge.tcirc.tw/ShowProblem?problemid=d038
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
int check(int,int,int,int);
vector<pair<int,int>>f;
vector<int>c;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    c.resize(b);
    for(int &i : c) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    sort(c.begin(),c.end());
    cout<<check(0,a - 1,0,b - 1);
    return 0;
}
int check(int l,int r,int cl,int cr) {
    debug(l,r,cl,cr);
    if(cl > cr) return 0;
    if(cl == cr) {
        int mmax = LONG_LONG_MIN;
        for(int i = l;i<=r;i++) {
            mmax = max(mmax,f[i].first * c[cl] + f[i].second);
        }
        // printf("%d %d\n",cl,mmax);
        return mmax;
    }
    int mid = (cl + cr) >> 1;
    int mmax = LONG_LONG_MIN;
    int d = -1;
    for(int i = l;i<=r;i++) {
        auto now = f[i];
        if(mmax < c[mid] * f[i].first + f[i].second) {
            mmax = c[mid] * f[i].first + f[i].second;
            d = i;
        }
    }
    // printf("%d %d\n",mid,mmax);
    return mmax + check(l,d,cl,mid - 1) + check(d,r,mid + 1,cr);
}