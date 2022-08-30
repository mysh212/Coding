// Author : ysh
// 08/25/2022 Thu  7:13:29.95
// https://tioj.ck.tp.edu.tw/problems/2224
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int R = 1e12;
int r = 0;
void check(vector<vector<pair<int,int>>>&g,vector<pair<int,int>>&t,vector<bool>&mark,int n) {
    if(mark[n]) return;
    mark[n] = 1;
    for(auto i : g[n]) {
        check(g,t,mark,i.first);
    }
    t.emplace_back(r++,n);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>g(a);
    vector<pair<int,int>>t;
    vector<int>mark(a,R);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        g[a - 1].emplace_back(b - 1,c);
    }
    {
    vector<bool>tmp(a);
    for(int i = 0;i<a;i++) {
        check(g,t,tmp,i);
    }
    }
    sort(t.rbegin(),t.rend());
    mark[0] = 0;
    for(int i = 0;i<a;i++) {
        auto j = t[i].second;
        for(auto i : g[j]) {
            mark[i.first] = min(mark[i.first],mark[j] + i.second);
        }
    }
    int ans = 0;
    for(auto i : mark) {
        ans += i;
    }
    cout<<ans;
    return 0;
}