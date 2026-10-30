// Author : ysh
// 2026/10/24 Sat 21:45:07
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 998244353
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<vc<pair<int, int>>>f(a);
    while(b--) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b, c});
        // f.at(b).push_back({a, c});
    }
    repo(&i, f) sort(all(i), [](auto &l, auto &r) {
        if(l.second == r.second) return l.first < r.first;
        return l.second < r.second;
    });
    
    vector<int>dt(a, -1);
    function<void()> check = [&] () {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>q[2];
        q[0].push({0, 0});
        int i = 0;
        while(1) {
            short k = (i++) & 1;
            if(q[k].empty()) break;
            while(!q[k].empty()) {
                auto [_, d, l] = q[k].top(); q[k].pop();

                if(dt.at(d) != -1) continue;
                dt.at(d) = l;
        
                repo(&i, f.at(d)) {
                    if(dt.at(i.first) != -1) continue;
                    debug(d, i);
        
                    q[!k].push({i.second, i.first, int((((1LL * l) * 10) + i.second) % R)});
                }
            }
        }
        return;
    };

    check();
    re(i, 1, a) outl(dt.at(i));
    return 0;
}