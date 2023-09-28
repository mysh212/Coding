// Author : ysh
// 2023/06/29 Thu 22:42:31
// https://codeforces.com/problemset/problem/1140/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.second>>i.first;
    sort(f.rbegin(),f.rend());

    priority_queue<int,vector<int>,greater<int>>q;
    int mmin = INT_MAX,ans = 0,sig = 0;
    for(auto &i : f) {
        mmin = min(i.first,mmin);
        q.push(i.second);
        sig = sig + i.second;
        if(q.size() > k) sig = sig - q.top(),q.pop();
        ans = max(ans,sig * mmin);
    }
    cout<<ans;
    return 0;
}