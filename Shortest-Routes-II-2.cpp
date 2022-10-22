// Author : ysh
// 10/10/2022 Mon 12:39:51.65
// https://cses.fi/problemset/task/1672
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
        f.at(b).push_back({a,c});
    }
    vector<vector<int>>dt(a,vector<int>(a,-1));
    for(int i = 0;i<a;i++) dt[i][i] = 0;
    function<void(int)> check = [&] (int r) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,r);
        vector<bool>mark(a);
        // for(int i = 0;i<a;i++) if(dt[r][i] != -1 && i != r) mark.at(i) = 1;
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            dt.at(r).at(d) = l;
            dt.at(d).at(r) = l;
            for(auto &i : f.at(d)) {
                q.emplace(l + i.second,i.first);
            }
        }
        return;
    };
    for(int i = 0;i<a;i++) {
        check(i);
    }
    while(c--) {
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<dt[a][b]<<"\n";
    }
    return 0;
}