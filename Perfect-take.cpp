// Author : ysh
// 02/14/2022 Mon 13:00:20.27
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void opt(bool n) {
    if(n) cout<<"yeah!";
    else cout<<"oh no...";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    if(a*6+15>c) {
        opt(0);
        return 0;
    }
    if(b * 6 - 15 < c) {
        opt(0);
        return 0;
    }
    opt(1);
    return 0;
}