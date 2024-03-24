// Author : ysh
// 2024/02/22 Thu 14:21:37
// https://codeforces.com/contest/1926/problem/D
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
    // cout<<((~0) & INT_MAX);
    // return 0;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,bool>>f(n);
        for(auto &i : f) cin>>i.first;

        sort(f.begin(),f.end(),[] (pair<int,bool>a,pair<int,bool>b) {
            return a.first < b.first;
        });
        int ans = 0;
        for(auto &i : f) {
            if(i.second) continue;
            ans++;
            auto found = lower_bound(f.begin(),f.end(),(~(i.first)) & INT_MAX,[] (pair<int,bool> a,int b) {
                return a.first < b;
            });
            if(found == f.end()) continue;
            while(found->second && next(found) != f.end()) found = next(found);
            if(found->first != ((~(i.first)) & INT_MAX)) continue;
            debug(i.first,(~(i.first)) & INT_MAX);
            found->second = true;
        }
        debug(f);

        cout<<ans<<" ";
    }
    return 0;
}