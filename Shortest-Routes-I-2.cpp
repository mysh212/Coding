// Author : ysh
// 2025/01/24 Fri 11:34:54
// https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    while(b--) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
    }

    vector<int>dt(a,-1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.emplace(0,0);
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

    for(int &i : dt) cout<<i<<" ";
    return 0;
}