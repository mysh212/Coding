// Author : ysh
// 2026/11/07 Sat 21:27:06
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    auto g = f;

    int last = 0;
    repo(&i, f) i = last += i;

    int ans = abs(f.back()); // abs(accumulate(all(g), 0LL));
    re(2) {
        debug(f);
        vc<int>l(n), r(n);

        l[0] = min(f[0], 0);
        r[n - 1] = max(0, f[n - 1]);

        re(i, 1, n) l[i] = min(l[i - 1], f[i]);
        for(int i = n - 2; i >= 0; i--) r[i] = max(r[i + 1], f[i]);

        debug(l, r);

        re(i, n) {
            int ll = (i == 0 ? 0 : l[i - 1]);
            int rr = (i == n - 1 ? 0 : r[i + 1]);

            debug(ll, rr);

            ans = max(ans, rr - ll + ((-g[i]) << 1));
            debug(rr - ll + ((-g[i]) << 1));
        }

        repo(&i, f) i = -i;
        repo(&i, g) i = -i;
    }

    out(ans + 1);
    return 0;
}