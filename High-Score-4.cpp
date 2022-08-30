// Author : ysh
// 08/26/2022 Fri 19:25:09.10
// https://cses.fi/problemset/task/1673
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<array<int,3>>f;
    vector<pair<int,int>>to[a];
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.push_back({a - 1,b - 1,c});
        to[a - 1].emplace_back(b - 1,c);
    }
    vector<int>dt(a,-1e10);
    // vector<int>bp;
    dt[0] = 0;
    int bp = 0;
    for(int i = 0;i<a - 1;i++) {
        for(auto i : f) {
            dt[i[1]] = max(dt[i[1]],dt[i[0]] + i[2]);
        }
        if(i == a - 2) {
            bp = dt[a - 1];
        }
        if(i >= a - 1) {
            if(dt[a - 1] != bp) {
                cout<<"-1";
                return 0;
            }
        }
    }
    vector<bool>mark(a);
    vector<bool>cy(a);
    function<bool(int)> check = [&] (int n) {
        if(n == a - 1) {
            return 1;
        }
        if(mark[n]) return 0;
        mark[n] = 1;
        for(auto i : to[n]) {
            int now = i.first;
            if(check(now)) {
                cy[n] = 1;
            }
        }
        return 0;
    };
    check(0);
    for(bool i : cy) {
        cout<<(int) i<<" ";
    }
    for(auto i : f) {
        if(dt[i[0]] + i[2] > dt[i[1]]) {
            if(cy[i[0]]) {
                cout<<"-1";
                return 0;
            }
        }
    }
    cout<<dt[a - 1];
    return 0;
}