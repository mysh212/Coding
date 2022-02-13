// Author : ysh
// 02/13/2022 Sun 14:05:19.33
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    cout<<((a - (a / 3)) + (b - (b / 3)) + (c - (c / 3))) * n;
    return 0;
}