// Author : ysh
// 03/22/2022 Tue  9:18:35.58
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int,int,int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    while(cin>>a) {
        int n;cin>>n;
        int p;cin>>p;
        cout<<check(a,n,p) % p<<"\n";
    }
    return 0;
}
int check(int a,int b,int c) {
    if(b == 0) return 0;
    int now = check(a,b >> 1,c);
    if(b & 1) return (a + (now + now) % c) % c;
    else return (now + now % c) % c;
}