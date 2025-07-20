// Author : ysh
// 2025/05/22 Thu 10:28:37
// https://atcoder.jp/contests/arc084/tasks/arc084_b
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    if(n == 1) return cout<<1, 0;

    // vector<vector<pair<int,int>>>f(n);
    // for(int i = 0;i<n;i++) {
    //     f.at(i).push_back({(i * 10) % n, 0});
    //     f.at(i).push_back({(i + 1) % n, 1});
    // }

    vector<bool>mark(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0, 1);
    while(!q.empty()) {
        int l, d;
        tie(l, d) = q.top(); q.pop();

        if(mark.at(d)) continue;
        mark.at(d) = 1;

        if(d == 0) return cout<<l + 1, 0;

        q.emplace(l + 1, (d + 1) % n);
        q.emplace(l, (d * 10) % n);
    }

    return -1;
}