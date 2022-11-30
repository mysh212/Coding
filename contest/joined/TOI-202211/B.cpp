// Author : ysh
// 11/30/2022 Wed 21:32:09.78
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#define int long long
inline bool cp(pair<int,int>a,int b) {
    return a.first < b;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    vector<int>tmp(n,1);
    tree<int>t(tmp);
    queue<int>q;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        q.push(a);
        f.at(i) = {b,i};
    }
    int ans = 0;
    sort(f.begin(),f.end());
    while(!q.empty()) {
        int now = q.front();q.pop();
        auto found = lower_bound(f.begin(),f.end(),now,cp);
        int ffound = 0;
        for(auto i = found;i != f.end();i = next(i)) {
            if(i->second == -1) continue;
            ffound = i->second;
            i->second = -1;
            break;
        }
        t.add(ffound,-1);
        ans = ans + t.sum(0,ffound);
    }
    cout<<ans;
    return 0;
}