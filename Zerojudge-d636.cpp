// Author : ysh
// 03/21/2022 Mon 22:10:25.65
#include<bits/stdc++.h>
using namespace std;
#define p 10007
#define int long long
int check(int,int,int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    int n;cin>>n;
    //int p;cin>>p;
    cout<<check(a,n,p) % p;
    return 0;
}
int check(int a,int b,int c) {
    if(b == 0) return 1;
    int now = check(a,b >> 1,c);
    if(b & 1) return a * (now * now) % c;
    else return now * now % c;
}
