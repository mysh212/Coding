// Author : ysh
// 03/06/2023 Mon 12:47:05.35
// https://judge.tcirc.tw/ShowProblem?problemid=d103
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<pair<int,int>>>f(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        // a--;
        f.at(i).push_back({a,b});
        f.at(a).push_back({i,b});
    }

    vector<bool>mark(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0,0);
    int ans = 0;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int d = now.second;
        int l = now.first;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        ans = max(ans,l);
        for(auto &i : f.at(d)) {
            q.emplace(l + i.second,i.first);
        }
    }

    int mmax,d;mmax = d = 0;
    function<void(int,int,int)> check = [&] (int last,int x,int level) {
        if(level > mmax) {
            mmax = level;
            d = x;
        }
        for(auto &i : f.at(x)) {
            if(i.first == last) continue;
            check(x,i.first,level + 1);
        }
        return;
    };

    check(-1,0,0);
    cout<<ans<<"\n"<<mmax;
    return 0;
}