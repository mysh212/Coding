// Author : ysh
// 01/07/2023 Sat 21:00:37.69
// https://judge.tcirc.tw/ShowProblem?problemid=d108
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

vector<vector<pair<int,int>>>f;
vector<int>level,deep;
int sig = 0;
int check(int n,int l,int dt) {
    debug(n,l,dt);
    level.at(n) = l;
    sig = sig + dt;
    int ans = 0;
    for(auto &i : f.at(n)) {
        ans = ans + check(i.first,l + 1,dt + i.second);
    }
    return deep.at(n) = ans + 1;
}
int n;
int ans = 0;
void side(int n,int d) {
    debug(n,d);
    ans = ans + d;
    for(auto &i : f.at(n)) {
        side(i.first,d + i.second * (::n - (deep.at(i.first) << 1)));
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f.resize(n);
    level.resize(n);
    deep.resize(n);
    vector<array<int,3>>a(n - 1);
    for(int i = 0;i<n - 1;i++) {
        cin>>a[i][0];
        a[i][0] = a[i][0] - 1;
        a[i][1] = i + 1;
    }
    for(int i = 0;i<n - 1;i++) {
        cin>>a[i][2];
    }
    for(auto &i : a) {
        f.at(i[0]).push_back({i[1],i[2]});
    }
    check(0,0,0);
    side(0,sig);
    cout<<ans;
    return 0;
}