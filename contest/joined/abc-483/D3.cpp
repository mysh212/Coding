// Author : ysh
// 2026/11/07 Sat 21:19:17
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    vc<pair<int, int>>l(n), r(n);

    int mmax = INT_MIN, mmin = INT_MAX;
    int now = 0;
    re(i, n) l.at(i) = {mmax = max(mmax, now += f.at(i)), mmin = min(now, mmin)};

    mmax = INT_MIN, mmin = INT_MAX;
    now = 0;
    for(int i = n - 1; i >= 0; i--) r.at(i) = {mmax = max(mmax, now += f.at(i)), mmin = min(now, mmin)};

    int ans = 0;
    re(i, n) {
        ans = max(r.at(i).first - l.at(i).second + abs(f.at(i)), l.at(i).first - r.at(i).second + abs(f.at(i)));
    }

    out(ans + 1);
    return 0;
}