// Author : ysh
// 2025/05/21 Wed 23:30:29
// https://www.luogu.com.cn/problem/P3403
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define int unsigned long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;

    if(b > c) swap(b, c);
    if(a > b) swap(a, b);

    vc<vc<pair<int,int>>>f(a);
    re(i, a) {
        f.at(i).push_back({(i + b) % a, b});
        f.at(i).push_back({(i + c) % a, c});
    }

    vector<int>dt(a, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.emplace(0, 0);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;

        if(dt.at(d) != -1) continue;
        dt.at(d) = l;

        for(auto &i : f.at(d)) {
            q.emplace(l + i.second, i.first);
        }
    }

    int ans = 0;
    repo(&i, dt) {
        if(i <= n - 1) ans += (n - 1 - i) / a + 1;
    }

    out(ans);
    return 0;
}