// Author : ysh
// 12/12/2022 Mon 11:12:25.01
// https://judge.tcirc.tw/ShowProblem?problemid=d017
#include<bits/stdc++.h>
using namespace std;
int t;
#define int long long
int check(int x,int r) {
    if(r == 1) return x % t;
    int ans = check(x,r >> 1);
    if(r & 1) return (((ans * ans) % t) * x) % t;
    return (ans * ans) % t;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    t = b;
    while(a--) {
        int tmp;cin>>tmp;
        cout<<check(tmp,b - 2)<<" ";
    }
    return 0;
}