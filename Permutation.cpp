// Author : ysh
// 02/06/2023 Mon 22:23:59.33
// https://codeforces.com/gym/412932/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    int t = 0;
    while(n--) cin>>t;
    t = 0;
    for(auto &i : f) i.second = ++t;
    for(auto &i : f) cin>>i.first;
    sort(f.rbegin(),f.rend());
    for(auto &i : f) cout<<i.second<<" ";
    return 0;
}