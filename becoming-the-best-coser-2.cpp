// Author : ysh
// 07/20/2022 Wed 20:58:28.23
// http://choj.me/problem/c005
#include<bits/stdc++.h>
using namespace std;
inline bool cp(pair<int,int>a,pair<int,int>b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    for(int j = 0;j<m;j++) {
        int n;cin>>n;
        vector<pair<int,int>>f(n);
        for(auto &i : f) {
            cin>>i.second;
        }
        for(auto &i : f) {
            cin>>i.first;
            i.first = i.second - i.first;
        }
        sort(f.begin(),f.end(),cp);
        int now = 0;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(now <= f[i].first) {
                now = f[i].second;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}