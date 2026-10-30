// Author : ysh
// 2026/10/25 Sun 11:57:53
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 998244353
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;

    vc<vc<pair<int, short>>>f(n);
    re(m) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b, c});
    }

    repo(&i, f) ranges::sort(i, {}, &pair<int, short>::second);

    vc<int>dt(n, -1);
    priority_queue<array<int, 4>, vc<array<int, 4>>, greater<array<int, 4>>>q[2];
    int t = 0;
    q[0].push({0, ++t, 0, 0});
    int k = 1;
    while(1) {
        k = !k;
        if(q[k].empty()) break;
        while(!q[k].empty()) {
            auto [_, __, l, d] = q[k].top(); q[k].pop();

            if(dt.at(d) != -1) continue;
            dt.at(d) = l;

            repo(&i, f.at(d)) {
                q[!k].push({i.second, ++t, ((1LL * l * 10) + i.second) % R, i.first});
            }
        }
    }

    re(i, 1, n) outl(dt.at(i));
    return 0;
}