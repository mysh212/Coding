// Author : ysh
// 06/02/2023 Fri 17:58:20.34
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<pair<int,int>>f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(auto &i : f) cin>>i.first>>i.second;
    sort(f.begin(),f.end(),[](pair<int,int>&a,pair<int,int>&b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    vector<pair<int,int>>v;
    // vector<int>ans(n);
    int ans = 0;
    v.push_back({INT_MIN,0});
    for(int i = 0;i<n;i++) {
        auto found = prev(upper_bound(v.begin(),v.end(),f.at(i).second - f.at(i).first,[] (int a,pair<int,int> &b) {
            return a < b.first;
        }));
        ans = max(ans,found->second + 1);
        if(not v.back().second >= found->second + 1) v.push_back({max(0,found->first) + f.at(i).first,found->second + 1});
    }
    debug(v);
    cout<<ans;
    return 0;
}