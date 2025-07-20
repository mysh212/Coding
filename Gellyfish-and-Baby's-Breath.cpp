// Author : ysh
// 2025/05/31 Sat 23:06:08
// https://codeforces.com/contest/2116/problem/B
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
#define R 998244353
constexpr array<int, MAX + 1> init() {
    array<int, MAX + 1> ans;
    ans[0] = 1;
    for(int i = 1;i<=MAX;i++) ans[i] = (ans[i - 1] << 1) % R;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    constexpr auto pre = init();
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,int>>f(n);
        for(auto &i : f) cin>>i.first;
        for(auto &i : f) cin>>i.second;

        int lmax, rmax;lmax = f[0].first, rmax = f[0].second;
        int l, r; l = r = 0;
        for(int i = 0;i<n;i++) {
            if(f[i].first > lmax) lmax = f[i].first, l = i;
            if(f[i].second > rmax) rmax = f[i].second, r = i;
            
            cout<<max(pre[lmax] + pre[f.at(i - l).second], pre[rmax] + pre[f.at(i - r).first]) % R<<" ";
        }
        cout<<"\n";
    }
    return 0;
}