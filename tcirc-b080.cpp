// Author : ysh
// 12/12/2022 Mon 11:22:27.38
// https://judge.tcirc.tw/ShowProblem?problemid=b080
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y,int &a,int &b) {
    // if(x < y) swap(x,y);
    if(y == 0) {
        a = 0,b = 1;
        return x;
    }
        // cerr<<1;
    int tmp = gcd(y,x % y,a,b);
    int tt = a;
    a = b - (x / y) * a;
    b = tt;
    return tmp;
}
int check(int x,int r) {
    int a,b;
    int t = gcd(r,x,a,b);
    if(t != 1) return -1;
    return ((a % r) + r) % r;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    while(a--) {
        int a;cin>>a;
        cout<<check(a,b)<<"\n";
    }
    return 0;
}