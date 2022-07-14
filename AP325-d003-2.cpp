// Author : ysh
// 07/14/2022 Thu 15:58:19.74
// WA
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
int check(int,int);
set<int,less<int>>s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        // assert(tmp != 0 && tmp != b && tmp != b - 1);
        s.insert(tmp);
    }
    cout<<check(0,b);
    return 0;
}
int check(int l,int r) {
    if(l >= r) return 0;
    double mid = ((l + r) / 2);
    auto found = s.lower_bound(mid);
    // int t = (int) *found;
    // debug(l,r,t);
    bool br = 0,bl = 0;
    if(found == s.end() || *found >= r || *found <= l) {
        br = 1;
    }
    if(found == s.begin() || *(prev(found)) <= l || *(prev(found)) >= r) {
        bl = 1;
    }
    if(br == 1 && bl == 1) return 0;
    double dt = LONG_LONG_MAX;
    int ans = 0;
    if(!br) {
        dt = *found - mid;
        ans = *found;
    }
    if(!bl) {
        if(mid - *(prev(found)) <= dt) {
            dt = mid - *(prev(found));
            ans = *(prev(found));
        }
    }
    // printf("%d,%d ==> %d , %d\n",l,r,*found,*(prev(found)));
    return check(l,ans) + check(ans,r) + (r - l);
}