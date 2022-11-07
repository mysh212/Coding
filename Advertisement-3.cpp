// Author : ysh
// 10/29/2022 Sat 12:59:39.97
// https://cses.fi/problemset/task/1142/
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
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    vector<vector<int>>l(2,vector<int>(n));
    vector<pair<int,int>>r;
    for(int i = 0;i<=1;i++) {
        r.clear();
        r.push_back({-1,-1});
        for(int j = 0;j<n;j++) {
            // debug(j,r);
            while(!r.empty() && r.back().first >= f.at(j)) r.pop_back();
            if(!r.empty()) l[i][j] = r.back().second;
            r.push_back({f.at(j),j});
        }
        reverse(f.begin(),f.end());
    }
    debug(l);
    long long ans = 0;
    for(int i = 0;i<n;i++) {
        ans = max(ans,((n - 1) - l[1][(n - 1) - i] - l[0][i] - 1) * 1LL * f.at(i) * 1LL);
    }
    cout<<ans;
    return 0;
}