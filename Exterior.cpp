// Author : ysh
// 02/06/2023 Mon 15:12:51.96
// https://codeforces.com/gym/425267
#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    vector<vector<pair<int,int>>>v(a + 1);
    for(int &i : f) cin>>i;
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(c >= f.at(a) + f.at(b)) continue;
        v.at(a).push_back({b,c});
        v.at(b).push_back({a,c});
    }
    for(int i = 0;i<a;i++) v.at(a).push_back({i,f.at(i)}),v.at(i).push_back({a,f.at(i)});
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.emplace(0,0);
    vector<bool>mark(a + 1);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        long long l = now.first;
        int d = now.second;
        if(d == a - 1) {
            cout<<l;
            return 0;
        }
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        for(auto &i : v.at(d)) {
            if(!mark.at(i.first)) q.emplace(l + i.second,i.first);
        }
    }
    return -1;
}