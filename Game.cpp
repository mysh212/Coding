// Author : ysh
// 02/06/2023 Mon 20:46:13.72
// https://codeforces.com/gym/412932/problem/D
#include<bits/stdc++.h>
using namespace std;
// #define c __gcd
#include<table>
// #undef c
// pair<int,vector<int>> check(vector<int>f) {
//     int n = f.size();
//     int ans,d;ans = d = 0;
//     for(int i = 0;i<n;i++) {
//         int now = f.at((i == 0 ? 1 : 0));
//         for(int j = 0;j<n;j++) {
//             if(i == j) continue;
//             now = __gcd(now,f.at(j));
//         }
//         if(now > ans) ans = now,d = i;
//     }
//     f.erase(f.begin() + d);
//     return {ans,f};
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    sort(f.begin(),f.end());
    for(int &i : f) cin>>i;
    table<int>t(f,[] (int a,int b) {
        return __gcd(a,b);
    });
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(i >= j) continue;
            int r = 0;
            if(j != n - 1) r = t.get(j + 1,n - 1);
            if(i != 0) t.get(i + 1,j - 1);
            if(i == 0 && j == n - 1) r = t.get(i + 1,j - 1);
            cerr<<r<<" ";
            if(j != n - 1) r = __gcd(r,t.get(j + 1,n - 1));
            if(i != 0) r = __gcd(r,t.get(0,i - 1));
            if(i + 1 != j) r = __gcd(r,t.get(i + 1,j - 1));
            cerr<<i<<" "<<j<<" "<<ans<<"\n";
            ans = max(ans,r);
        }
    }
    cout<<ans;
    return 0;
}