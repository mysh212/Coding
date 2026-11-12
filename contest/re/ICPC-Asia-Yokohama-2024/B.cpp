// Author : ysh
// 2026/11/05 Thu 14:52:37
#include<bits/stdc++.h>
using namespace std;
#define R 63
#define int uint64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;cin>>l>>r;
    if(l > r) swap(l, r);
    int ans = 0;
    int i = R;
    for(; i >= -1; i--) {
        if(i == -1) break;
        int mask = (1LL << i);
        if((l & mask) != (r & mask)) break;
        if(r & mask) ans = ans | mask;
    }

    if(i != -1 && (ans < l)) {
        while(i != -1 && (ans | (1 << i)) >= l) i--;
        ans = ans | (1 << (i + 1));
    }

    cout<<ans;
    return 0;
}