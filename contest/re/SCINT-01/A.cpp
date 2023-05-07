// Author : ysh
// 05/06/2023 Sat 20:30:11.00
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f((int) 2e5 + 1);
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        q.push(tmp);
    }
    vector<pair<int,int>>tmp(b);
    for(int i = 0;i<b;i++) {
        cin>>tmp.at(i).first;
    }
    for(int i = 0;i<b;i++) {
        cin>>tmp.at(i).second;
    }
    for(auto &j : tmp) {
        f.at(j.first).push_back(j.second);
    }

    int ans = 0;
    while(!q.empty()) {
        int now = q.top();q.pop();
        if(now >= c) break;
        c = c + now;
        ans++;
        for(int &i : f.at(ans)) {
            q.push(i);
        }
    }
    cout<<ans;
    return 0;
}