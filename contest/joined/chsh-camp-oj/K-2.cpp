// Author : ysh
// 2023/07/07 Fri 16:29:37
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> check(int a,vector<vector<pair<int,int>>>&f,int x) {
    vector<bool>mark(a);
    vector<int>ans(a,(1e13));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0,x);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        ans.at(d) = l;
        for(auto &j : f.at(d)) {
            q.emplace(l + j.second,j.first);
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<bool>v(a);
    while(c--) {
        int tmp;cin>>tmp;
        v.at(tmp - 1) = 1;
    }

    vector<vector<pair<int,int>>>f[2];
    f[0] = f[1] = vector<vector<pair<int,int>>>(a);
    while(b--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;
        f[0].at(a).push_back({b,c});
        f[0].at(b).push_back({a,c});
        f[1].at(a).push_back({b,d});
        f[1].at(b).push_back({a,d});
    }

    vector<int>l,r;
    l = check(a,f[0],0);
    r = check(a,f[1],a - 1);
    long long ans = LLONG_MAX;

    int t = 0;
    for(bool i : v) {
        if(i) ans = min(l[t] * 1LL + r[t],ans);
        t++;
    }
    cout<<ans;
    return 0;
}