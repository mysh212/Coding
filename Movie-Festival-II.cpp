// Author : ysh
// 01/09/2023 Mon 16:12:20.93
// https://cses.fi/problemset/task/1632
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    multiset<int,greater<int>>s;
    while(b--) s.insert(-1);
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        return a.second < b.second;
    });
    int ans = 0;
    for(auto &i : f) {
        auto found = s.lower_bound(i.first);
        if(found != s.end()) {
            s.insert(i.second);
            s.erase(found);
            ans = ans + 1;
        }
    }
    cout<<ans;
    return 0;
}