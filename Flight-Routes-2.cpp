// Author : ysh
// 10/14/2022 Fri 19:19:59.24
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
    queue<int>ans;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int d = now.second;
        int l = now.first;
        if(d == a - 1) {
            ans.push(l);
            if(ans.size() == c) {
                while(!ans.empty()) {
                    cout<<ans.front()<<" ";ans.pop();
                }
                return 0;
            }
        }
        for(auto &i : f.at(d)) {
            q.emplace(l + i.second,i.first);
        }
    }
    return -1;
}