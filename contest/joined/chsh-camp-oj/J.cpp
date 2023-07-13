// Author : ysh
// 2023/07/07 Fri 16:04:57
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    vector<vector<pair<int,int>>>f(a);
    while(b--) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
        f.at(b).push_back({a,c});
    }

    vector<int>ans(a);
    vector<bool>mark(a);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        ans.at(d) = l;
        for(auto &i : f.at(d)) {
            q.emplace(l + i.second,i.first);
        }
    }

    for(int i : ans) cout<<i<<" ";
    return 0;
}