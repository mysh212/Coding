// Author : ysh
// 07/14/2022 Thu 22:28:10.35
// https://judge.tcirc.tw/ShowProblem?problemid=d012
#include<bits/stdc++.h>
using namespace std;
#define int long long
int xx,y,z;
int check(int x) {
    if(x == 1) return xx;
    int tmp = check(x >> 1);
    if(x & 1) return ((tmp * tmp) % z * xx) % z;
    return (tmp * tmp) % z;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>xx>>y>>z;
    cout<<check(y);
    return 0;
}