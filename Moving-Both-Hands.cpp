// Author : ysh
// 2023/11/12 Sun 08:56:29
// https://codeforces.com/problemset/problem/1725/M
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a),re(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
        re.at(b).push_back({a,c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[2];
    vector<int>dt(a,-1);
    q[0].emplace(0,0);
    q[1].emplace(0,0);
    for(int i = 0;i<=1;i++) {
        vector<bool>mark(a);
        while(!q[i].empty()) {
            auto now = q[i].top();q[i].pop();
            int l = now.first;
            int d = now.second;
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            dt.at(d) = l;
            for(auto &j : (i == 0 ? f.at(d) : re.at(d))) {
                q[i].emplace(l + j.second,j.first);
                if(i == 0) q[1].emplace(l + j.second,j.first);
            }
        }
    }
    for(int i = 1;i<a;i++) cout<<dt[i]<<" ";
    return 0;
}