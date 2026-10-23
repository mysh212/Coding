// Author : ysh
// 2026/09/19 Sat 09:57:02
#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vector<vector<array<int, 3>>>f(a);
    while(b--) {
        int a, b, c, d;cin>>a>>b>>c>>d;
        a--;b--;
        f.at(a).push_back({b, c, d});
        f.at(b).push_back({a, c, d});
    }

    priority_queue<pair<int, int>>q;
    q.emplace(INT_MAX, 0);

    vector<bool>mark(a);
    
    while(!q.empty()) {
        auto [l, d] = q.top(); q.pop();

        if(l < 0) break;

        if(mark.at(d)) continue;
        mark.at(d) = 1;

        for(auto &[nd, t, h] : f.at(d)) {
            q.emplace(min(h - t, l - t), nd);
        }
    }

    for(int i = 0;i<a;i++) cout<<(mark.at(i) ? 1 : 0);
    return 0;
}