// Author : ysh
// 11/22/2022 Tue 23:34:15.03
// https://cses.fi/problemset/task/1734
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>ans;
    vector<vector<int>>g(a);
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        ans.push_back({a - 1,b - 1});
        g.at(a - 1).push_back(b - 1);
    }
    seg_tree<int>t(a);
    unordered_map<int,int>m;
    map<pair<int,int>,int>r;
    for(int i = a - 1;i>=0;i--) {
        int &now = f.at(i);
        auto found = m.find(now);
        if(found != m.end()) {
            t.add(found->second,found->second,-1);
            found->second = i;
            t.add(i,i,1);
        } else {
            t.add(i,i,1);
            m.insert({now,i});
        }
        for(auto &j : g.at(i)) {
            r.insert({{i,j},t.sum(i,j)});
        }
    }
    for(auto i : ans) {
        cout<<r.find(i)->second<<"\n";
    }
    return 0;
}