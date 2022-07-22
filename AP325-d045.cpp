// Author : ysh
// 07/20/2022 Wed 20:44:54.03
// https://judge.tcirc.tw/ShowProblem?problemid=d045
#include<bits/stdc++.h>
using namespace std;
inline bool cp(pair<int,int>a,pair<int,int>b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    sort(f.begin(),f.end(),cp);
    int now = INT_MIN;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        if(now < f[i].first) {
            now = f[i].second;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}