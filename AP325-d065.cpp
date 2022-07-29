// Author : ysh
// 07/29/2022 Fri 19:03:40.55
// https://judge.tcirc.tw/ShowProblem?problemid=d065
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
int check(vector<int> &f,int l,int r) {
    // debug(l,r);
    if(l >= r) {
        // debug(l,r,f[l]);
        return f[l];
    }
    int mid = (l + r) >> 1;
    int lf = check(f,l,mid);
    int rf = check(f,mid + 1,r);
    int nl,nr;nl = mid;nr = mid;
    int mmax = f[mid];
    int h = f[mid];
    while(nl > l || nr < r) {
        // assert(nl >= l && nr <= r);
        // debug(nl,nr,mmax,h);
        if(nl > l && f[nl - 1] >= h) {
            nl--;
            mmax = max(mmax,(nr - nl + 1) * h);
            continue;
        }
        if(nr < r && f[nr + 1] >= h) {
            nr++;
            mmax = max(mmax,(nr - nl + 1) * h);
            continue;
        }
        if(not (nr < r && nl > l)) {
            if(nr == r) {
                nl--;
                h = min(h,f[nl]);
                mmax = max(mmax,(nr - nl + 1) * h);
                continue;
            }
            nr++;
            h = min(h,f[nr]);
            // printf("%d",(nr - nl + 1) * h);
            mmax = max(mmax,(nr - nl + 1) * h);
            continue;
        }
        if(f[nr + 1] > f[nl - 1]) {
            nr++;
            h = min(h,f[nr]);
            mmax = max(mmax,(nr - nl + 1) * h);
            continue;
        }
        nl--;
        h = min(h,f[nl]);
        mmax = max(mmax,(nr - nl + 1) * h);
    }
    // debug(l,r,mmax);
    // debug(l,r,max({lf,rf,mmax}));
    return max({lf,rf,mmax});
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    cout<<check(f,0,n - 1);
    return 0;
}