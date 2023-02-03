// Author : ysh
// 02/01/2023 Wed 17:05:51.08
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#define int long long
#include<fast>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n,{-1,-1});
    tree<int>t(n << 1);
    for(int i = 0;i<(n << 1);i++) {
        int tmp;cin>>tmp;
        tmp--;
        if(f.at(tmp).first != -1) f.at(tmp).second = i;
        else f.at(tmp).first = i;
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        auto &now = f.at(i);
        ans = ans + t.sum(now.first,now.second);
        t.add(now.first,1);
        t.add(now.second,1);
    }
    cout<<ans;
    return 0;
}