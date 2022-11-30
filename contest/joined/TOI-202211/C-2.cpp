// Author : ysh
// 11/30/2022 Wed 21:57:11.30
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(a,INT_MIN);
    // a = a - 2;
    for(int i = 1;i<a - 1;i++) {
        cin>>f.at(i);
    }
    // f.push_back(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q;
    q.emplace(0,0);
    g.at(0) = 0;
    for(int i = 1;i<a;i++) {
        auto now = q.top();
        while(!q.empty() && now.second < i - b) {
            q.pop();now = q.top();
        }
        // for(int j = i - 1;j >= max(i - b,0);j--) {
        //     g.at(i) = max(g.at(i),g.at(j));
        // }
        g.at(i) = now.first;
        // if(i <= b) g.at(i) = max(g.at(i),0);
        g.at(i) = g.at(i) + f.at(i);
        q.emplace(g.at(i),i);
        // cerr<<g.at(i)<<" ";
    }
    cout<<g.at(a - 1);
    return 0;
}