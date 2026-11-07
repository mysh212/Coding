// Author : ysh
// 2026/11/07 Sat 21:11:49
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#include<tree>
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    tree<int64_t>t(f);
    
    int ans = abs(accumulate(all(f), 0LL));
    re(i, n) {
        int l = (i == 0 ? 0 : t.sum(0, i - 1));
        int r = (i == n - 1 ? 0 : t.sum(i + 1, n - 1));

        ans = max(ans, abs(l + (-f.at(i)) + r));
    }

    out(ans + 1);
    return 0;
}