// Author : ysh
// 2024/04/10 Wed 21:24:51
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.first>>i.second;

    sort(f.begin(),f.end(),[] (pair<int,int>&a,pair<int,int>&b) {
        return a.first < b.first;
    });
    int ans = 0;
    int r = f.front().first - 1;
    for(auto &i : f) {
        ans = ans + max(0,(i.second - max(i.first,r)));
        r = max(r,i.second);
    }
    cout<<ans;
    return 0;
}