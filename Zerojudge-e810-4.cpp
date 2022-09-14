// Author : ysh
// 09/09/2022 Fri 17:46:28.12
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a).push_back({b,c});
        f.at(b).push_back({a,c});
    }
    int c,e;cin>>c>>e;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<bool>mark(a);
    q.emplace(0,c);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(d == e) {
            cout<<l;
            return 0;
        }
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        for(auto i : f.at(d)) {
            q.emplace(max(l,i.second),i.first);
        }
    }
    cout<<"-1";
    return 0;
}