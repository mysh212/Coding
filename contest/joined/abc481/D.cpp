// Author : ysh
// 2026/10/24 Sat 20:10:14
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, l, r;cin>>a>>b>>l>>r;
    l--;r--;

    vc<pair<int, int>>f(b);
    // cin>>f;
    repo(&i, f) cin>>i;
    sort(all(f));

    vc<vc<int>>v(a);
    for(auto &[l, r] : f) v.at(l - 1).push_back(r - 1);

    #define f v

    priority_queue<pair<int, int>, vc<pair<int, int>>, greater<pair<int, int>>>q;
    vc<int>dt(a, -1);
    q.push({0, l});
    while(!q.empty()) {
        auto [l, d] = q.top(); q.pop();

        if(d == r) return out(l), 0;

        if(dt.at(d) != -1) continue;
        dt.at(d) = l;

        if(!f.at(d).empty()) q.push({l, f.at(d).front()});

        repo(&i, f.at(d)) q.push({l + 1, i});
    }

    out(-1);
    return 0;
}