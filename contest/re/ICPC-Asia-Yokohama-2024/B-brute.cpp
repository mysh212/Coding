// Author : ysh
// 2026/11/05 Thu 15:09:39
#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;cin>>l>>r;
    int ans = 100;
    int d = l;
    for(int i = l; i <= r; i++) if(__builtin_popcount(i) < ans) {
        d = i;
        ans = __builtin_popcount(i);
    }

    cout<<d;
    return 0;
}