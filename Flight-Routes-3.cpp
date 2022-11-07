// Author : ysh
// 11/05/2022 Sat 13:45:47.31
// https://cses.fi/problemset/task/1196
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0,0);
    vector<int>ct(a);
    vector<int>dt;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        ct.at(d)++;
        if(d == a - 1) {
            dt.push_back(l);
            if(ct.at(d) == c) break;
        }
        if(ct.at(d) > c) continue;
        for(auto &i : f.at(d)) {
            q.emplace(l + i.second,i.first);
        }
    }
    for(int &i : dt) cout<<i<<" ";
    return 0;
}