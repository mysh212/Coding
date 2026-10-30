// Author : ysh
// 2026/10/25 Sun 12:22:47
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 998244353
#undef nl
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
    
    vc<int>dt(n, -1);
    queue<vector<pair<int, int>>>q;
    q.push({{0, 0}});
    while(!q.empty()) {
        auto now = q.front(); q.pop();

        vc<pair<int, int>>pre[10];
        for(auto &[l, d] : now) {
            for(auto &[nd, nl] : f.at(d)) {
                pre[nl].push_back({l, nd});
            }
        }

        re(i, 10) {
            vc<pair<int, int>>now;
            for(auto &[l, d] : pre[i]) {
                if(dt.at(d) != -1) continue;

                int ans = (1LL * l * 10 + i) % R;
                dt.at(d) = ans;
                now.push_back({ans, d});
            }
            if(!now.empty()) q.push(move(now));
        }
    }

    re(i, 1, n) outl(dt[i]);
    return 0;
}