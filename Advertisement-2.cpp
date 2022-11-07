// Author : ysh
// 10/27/2022 Thu 18:25:06.75
// https://cses.fi/problemset/task/1142/
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
vector<int>f;
int ck(int l,int r) {
    if(l == r) return f.at(l);
    int mid = (l + r) >> 1;
    int ll = ck(l,mid);
    int rr = ck(mid + 1,r);
    int h = max(f.at(mid),f.at(mid + 1));
    int nl,nr;int mmax = 0;
    if(h == f.at(mid)) nl = nr = mid;
    else nl = nr = mid + 1;
    while(!(nl == l && nr == r)) {
        debug(l,r,nl,nr);
        int ll = ((nl > l) ? f.at(nl - 1) : 0);
        int rr = ((nr < r) ? f.at(nr + 1) : 0);
        if(ll == rr && rr == 0) break;
        h = min(max(ll,rr),h);
        // if(nl > l && f.at(nl - 1) >= f.at(nr + 1)) {
        //     h = f.at(--nl);
        // }
        // debug(l,r,nl,nr);
        // if(nr < r && f.at(nl - 1) <= f.at(nr + 1)) {
        //     h = f.at(++nr);
        // }
        debug(l,r,nl,nr);
        while(nl > l && f.at(nl - 1) >= h) {
            nl--;
        }
        debug(l,r,nl,nr);
        while(nr < r && f.at(nr + 1) >= h) {
            nr++;
        }
        mmax = max(mmax,h * (nr - nl + 1));
    }
    return max({mmax,ll,rr});
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    cout<<ck(0,n - 1);
    return 0;
}