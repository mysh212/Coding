// Author : ysh
// 05/27/2022 Fri 18:21:40.21
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f[a];
    int c,d,e;
    for(int i = 0;i<b;i++) {
        cin>>c>>d>>e;
        f[c].push_back({d,e});
        f[d].push_back({c,e});
    }
    // vector<bool>mark(a);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    cin>>c>>d;
    vector<int>vt(a,INT_MAX);
    vector<bool>bb(a);
    bb[c] = 1;
    map<pair<int,int>,bool>m;
    q.push({0,{INT_MIN,c}});
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int v = now.first;
        int mmax = now.second.first;
        int t = now.second.second;
        bb[t] = 1;
        for(auto i : f[t]) {
            if(bb[i.first] != 0) continue;
            // m[{t,i.first}] = 1;
            // m[{i.first,t}] = 1;
            q.push({v + i.second,{max(v,i.second),i.first}});
            vt[i.first] = min(vt[i.first],max(mmax,i.second));
            // if(i.first == d) {
            //     cout<<max(v,i.second)<<"\n";
            //     return 0;
            // }
        }
    }
    cout<<(vt[d] == INT_MAX ? -1 : vt[d]);
    return 0;
}