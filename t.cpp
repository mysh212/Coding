// Author : ysh
// 2025/07/16 Wed 13:03:42
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define int long long
int extgcd(int a, int b, int &x, int &y) {
    if(a < b) return extgcd(b, a, y, x);

    if(b == 0) return x = 1, y = 0, a;
    int ans = extgcd(b, a % b, x, y);
    tie(x, y) = make_pair(y, x - (a / b) * y);

    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(3);
    cin>>f;
    sort(all(f));
    int m;cin>>m;

    const int g = __gcd(f.at(0), f.at(1));
    const int t = (f.at(0) * f.at(1)) / g;
    const int l = t / f.at(0);
    const int r = t / f.at(1);
    debug(l, r);
    int ans = 0;
    re(i, m - (f.at(2) * n), (m - (f.at(2))) + 1, f.at(2)) {
        if(i <= 0) continue;
        debug(i);
        int x, y;
        int d = extgcd(f.at(0), f.at(1), x, y);
        if(i % d != 0) continue;

        d = i / d;
        x *= d;
        y *= d;

        // x - ll * l >= 1;  ll * l <= x - 1;  ll <= (x - 1) / l;
        // x - ll * l <= n;  ll * l >= x - n;  ll >= (x - n + (l - 1)) / l;
        // y + r * ll <= n;  r * ll <= n - y;  ll <= (n - y) / r;
        // y + r * ll >= 1;  r * ll >= 1 - y;  ll >= (1 - y + (r - 1)) / r;
        int tmp;
        {
            int a = (x - 1) / l;
            int b = (x - n + (l - 1)) / l;
            int c = (n - y) / r;
            int d = (1 - y + (r - 1)) / r;

            tmp = min(a, c) - max(b, d) + 1;
        }

        // int ll = max(0LL, x - 1) / l;
        // int rr = max(0LL, y - 1) / r;
        // int lll = max(0LL, n - y) / r;
        // int rrr = max(0LL, n - x) / l;
        // int llll = max(0LL, (x - n + (l - 1))) / l;
        // int rrrr = max(0LL, (y - n + (r - 1))) / r;

        // x - ll * l >= 1;
        // ll * l <= x - 1;
        // ll <= (x - 1) / l;

        // y+r*ll<=n;
        // r * ll <= n - y;
        // ll <= (n - y) / r;

        // x-l*ll<=n;
        // l*ll >= x - n;
        // ll >= (x - n + (l - 1)) / l;

        // debug(min(ll, lll) - llll + 1);

        // int tmp = (x == 0 || y == 0 ? 0 : 1) + (min(ll, lll)) + (min(rr, rrr));
        // debug(ll, rr, lll, rrr, llll, rrrr);
        // debug(x, y);
        debug(i, tmp);
        ans += tmp;
    }

    out(ans);
    return 0;
}