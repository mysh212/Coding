// Author : ysh
// 2023/08/09 Wed 18:00:27
// https://atcoder.jp/contests/abc309/tasks/abc309_d
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>dt(vector<vector<int>>&f,int x) {
    vector<int>dt(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0,x);
    vector<bool>mark(n);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        dt.at(d) = l;
        for(int &i : f.at(d)) {
            q.emplace(l + 1,i);
        }
    }
    return dt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    n = a + b;
    vector<vector<int>>f(a + b);
    for(int i = 0;i<c;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    vector<int>left(dt(f,0));
    vector<int>right(dt(f,(a + b) - 1));

    cout<<*max_element(left.begin(),left.begin() + a) + *max_element(right.end() - b,right.end()) + 1;
    return 0;
}