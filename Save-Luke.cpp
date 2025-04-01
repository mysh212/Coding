// Author : ysh
// 2024/11/06 Wed 23:20:03
// https://codeforces.com/contest/624/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;cin>>a>>b>>c>>d;
    int now = max(0,b - a);
    cout<<fixed<<setprecision(10)<<now * 1.0 / (c + d);
    return 0;
}