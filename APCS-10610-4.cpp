// Author : ysh
// 05/07/2022 Sat 12:55:43.75
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define w first
#define t second
inline bool cp(pair<int,int>a,pair<int,int>b) {
    return a.w*b.t < a.t * b.w;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i].w;
    }
    for(int i = 0;i<n;i++) {
        cin>>f[i].t;
    }
    sort(f.begin(),f.end(),cp);
    int ws = 0;
    int ans = 0;
    for(auto i : f) {
        ans += ws * i.t;
        ws += i.w;
    }
    cout<<ans;
    return 0;
}