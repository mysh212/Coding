// Author : ysh
// 10/10/2022 Mon 12:56:21.12
// https://cses.fi/problemset/task/1195
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f[a].push_back({b,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q,p;
    q.emplace(0,0);
    vector<bool>mark(a);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(d == a - 1) break;
        if(mark[d]) continue;
        mark[d] = 1;
        for(auto &i : f[d]) {
            q.emplace(l + i.second,i.first);
            p.emplace(l + (i.second >> 1),i.first);
        }
    }
    mark = vector<bool>(a);
    while(!p.empty()) {
        auto now = p.top();p.pop();
        int l = now.first;
        int d = now.second;
        if(d == a - 1) {
            cout<<l;
            return 0;
        }
        if(mark[d]) continue;
        mark[d] = 1;
        for(auto &i : f[d]) {
            p.emplace(l + i.second,i.first);
        }
    }
    return -1;
}