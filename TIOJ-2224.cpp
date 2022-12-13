// Author : ysh
// 12/13/2022 Tue  9:22:54.93
// https://tioj.ck.tp.edu.tw/problems/2224
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a),re(a);
    vector<int>to(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
        re.at(b).push_back({a,c});
        to.at(b)++;
    }
    vector<int>run;
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) q.push(i);
    }
    while(!q.empty()) {
        auto now = q.front();q.pop();
        run.push_back(now);
        for(auto &i : f.at(now)) {
            if(--to.at(i.first) == 0) q.push(i.first);
        }
    }
    int ans = 0;
    vector<int>dt(a,1e11);
    dt.at(0) = 0;
    for(int &i : run) {
        for(auto &j : re.at(i)) {
            dt.at(i) = min(dt.at(j.first) + j.second,dt.at(i));
        }
    }
    for(int &i : dt) ans = ans + i;
    cout<<ans;
    return 0;
}