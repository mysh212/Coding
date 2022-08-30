// Author : ysh
// 08/25/2022 Thu  6:52:52.49
// https://tioj.ck.tp.edu.tw/problems/1509
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f[2][a];
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[0][a - 1].push_back(make_pair(b - 1,c));
        f[1][b - 1].push_back(make_pair(a - 1,c));
    }
    int ans = 0;
    for(int k = 0;k<=1;k++) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,0);
        vector<int>mark(a,-1);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;
            if(mark[d] != -1) continue;
            mark[d] = l;
            ans += l;
            for(auto i : f[k & 1][d]) {
                q.emplace(l + i.second,i.first);
            }
        }
    }
    cout<<ans;
    return 0;
}