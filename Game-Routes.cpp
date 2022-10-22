// Author : ysh
// 10/13/2022 Thu 18:54:11.06
// https://cses.fi/problemset/task/1681
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e9 + 7;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a),re(a);
    vector<int>to(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        re.at(b).push_back(a);
        to.at(b)++;
    }
    vector<int>mark(a);
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) q.push(i);
    }
    mark.at(0) = 1;
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int i : f.at(now)) {
            if(--to.at(i) == 0) q.push(i);
        }
        for(int i : re.at(now)) {
            mark.at(now) += mark.at(i);
        }
        mark.at(now) = mark.at(now) % N;
        if(now == a - 1) break;
    }
    cout<<mark.at(a - 1);
    return 0;
}