// Author : ysh
// 10/27/2022 Thu 20:09:27.98
// https://192.168.193.20/problem/31
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n + 1);
    f.at(0) = INT_MIN;
    for(int i = 1;i<=n;i++) {
        cin>>f.at(i);
    }
    vector<pair<int,int>>l,r;
    vector<int>ll(n + 1),rr(n + 1);
    for(int i = 1;i<=n;i++) {
        debug(l);
        while(!l.empty() && f.at(i) <= l.back().second) l.pop_back();
        if(l.empty()) {
            ll.at(i) = i;
            l.push_back({i,f.at(i)});
            continue;
        }
        ll.at(i) = i - l.back().first;
        l.push_back({i,f.at(i)});
    }
    for(int i = n;i >= 1;i--) {
        while(!r.empty() && f.at(i) <= r.back().second) r.pop_back();
        if(r.empty()) {
            rr.at(i) = INT_MAX;
            r.push_back({i,f.at(i)});
            continue;
        }
        rr.at(i) = r.back().first - i;
        r.push_back({i,f.at(i)});
    }
    // debug(ll);
    // debug(rr);
    for(int i = 1;i<=n;i++) {
        cout<<min(ll.at(i),rr.at(i))<<" ";
    }
    return 0;
}