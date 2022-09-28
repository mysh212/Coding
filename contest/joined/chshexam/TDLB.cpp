#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<pair<int,int>>f[a];
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb,tmpc;cin>>tmpa>>tmpb>>tmpc;
        f[tmpa - 1].push_back({tmpb - 1,tmpc});
        f[tmpb - 1].push_back({tmpa - 1,tmpc});
    }
    for(int i = 0;i<c;i++) {
        int a,b;cin>>a>>b;
        f[a - 1].push_back({b - 1,0});
        //f[b - 1].push_back({a - 1,0});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[2];
    q[0].emplace(0,0);
    vector<bool>mark(a);
    int mmin = LONG_LONG_MAX;
    while(!q[0].empty()) {
        auto now = q[0].top();q[0].pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d)  = 1;
        if(d == a - 1) {
            mmin = min(mmin,l);
            break;
        }
        for(auto &i : f[d]) {
            if(i.second == 0) q[1].emplace(l + i.second,i.first);
            else q[0].emplace(l + i.second,i.first);
        }
    }
    mark = vector<bool>(a);
    while(!q[1].empty()) {
        auto now = q[1].top();q[1].pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d)  = 1;
        if(d == a - 1) {
            mmin = min(mmin,l);
            //return 0;
        }
        for(auto &i : f[d]) {
            if(i.second == 0) continue;
            q[1].emplace(l + i.second,i.first);
        }
    }
    cout<<(mmin == LONG_LONG_MAX ? -1 : mmin);
    return 0;
}
