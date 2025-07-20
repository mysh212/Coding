// Author : ysh
// 2025/06/26 Thu 23:38:46
// https://codeforces.com/contest/689/problem/B
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;
    repo(&i, f) i--;

    vc<int>dt(n, INT_MAX);
    vc<bool>mark(n);
    dt.at(0) = 0;

    queue<int>q;
    q.push(0);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        // debug(now);

        if(mark.at(now)) continue;
        mark.at(now) = 1;

        if(now != 0) dt.at(now - 1) = min(dt.at(now) + 1, dt.at(now - 1));
        if(now != n - 1) dt.at(now + 1) = min(dt.at(now) + 1, dt.at(now + 1));
        dt.at(f.at(now)) = min(dt.at(now) + 1, dt.at(f.at(now)));
        
        if(now != 0) q.push(now - 1);
        if(now != n - 1) q.push(now + 1);
        q.push(f.at(now));
    }

    outl(dt);
    return 0;
}