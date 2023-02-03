// Author : ysh
// 02/02/2023 Thu 18:23:24.38
// https://codeforces.com/problemset/problem/961/E
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(2e5);
    vector<int>g(n);
    tree<int>t(2e5);
    int ans = 0;
    for(int i = 0,r;i<n;i++) {
        cin>>r;
        r--;
        if(r < 2e5) f.at(r).push_back(i);
        g.at(i) = r;
        t.add(i,1);
    }
    for(int i = 0;i<n;i++) {
        ans = ans + t.sum(min(g.at(i),(int) 2e5 - 1));
        for(int &i : f.at(i)) {
            t.add(i,-1);
        }
    }
    for(int i = 0;i<n;i++) {
        if(i <= g.at(i)) ans--;
    }
    cout<<(ans >> 1);
    return 0;
}