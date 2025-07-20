// Author : ysh
// 2025/05/22 Thu 10:43:28
// https://www.luogu.com.cn/problem/P2371
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int int64_t
#define omod(i, j) ((i) % (j))
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    deque<int>f(a);
    for(int &i : f) cin>>i;

    sort(f.begin(), f.end());
    while(!f.empty() && f.front() == 0) f.pop_front(), a--;
    if(a == 0) return cout<<0, 0;

    int n = f.front();
    vector<int>dt(n, -1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0, 0);
    // cerr<<1;
    while(!q.empty()) {
        int l, d;
        tie(l, d) = q.top(); q.pop();

        if(dt.at(d) != -1) continue;
        dt.at(d) = l;

        for(int &i : f) {
            q.push({l + i, omod(d + i, n)});
        }
    }

    int ans = 0;
    debug(dt);
    for(int &i : dt) {
        if(i > c || i == -1) continue;
        if(i >= b) ans += (c - i) / n + 1;
        else ans += (c - i) / n - (b - i - 1) / n;
    }

    cout<<ans;
    return 0;
}