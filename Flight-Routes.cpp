// Author : ysh
// 09/10/2022 Sat 15:54:08.52
// https://cses.fi/problemset/task/1196
#include<bits/stdc++.h>
using namespace std;
// #define int long long
int input() {
    int ans = 0;
    while(1) {
        int a = (int) getchar();
        // cerr<<(int) a;
        if((char) a == ' ' || (char) a == '\n' || (char) a == EOF) break;
        ans = ans * 10 + (a - 48);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a - 1).push_back({b - 1,c});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q[2];
    q[0].emplace(0,0);
    // vector<bool>mark(a);
    // vector<int>ans;
    // printf("%d\n",c);
    for(int i = 0;i<c;i++) {
        vector<bool>mark(a);
        int r = i & 1;
        while(!q[r].empty()) {
            auto now = q[r].top();q[r].pop();
            long long l = now.first;
            int d = now.second;
            if(mark.at(d)) {
                q[!(r)].push(now);
                continue;
            }
            mark.at(d) = 1;
            if(d == a - 1) {
                cout<<l<<" ";
            }
            for(auto j : f.at(d)) {
                q[r].emplace(l + j.second,j.first);
            }
        }
    }
    // if(ans.size() == c) {
    //     for(int i : ans) {
    //         cout<<i<<" ";
    //     }
    //     return 0;
    // }
    // return -1;
    return 0;
}