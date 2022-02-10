// Author : ysh
// 02/07/2022 Mon 10:16:46.84
// https://codeforces.com/contest/1634/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool brk = 0;
bool check(int* a,int b,int all,int c,int n) {
    //cout<<1;
    if(brk == 1) return 1;
    if(b == n) {
        if(all == c) {
            brk = 1;
            return 1;
        }
        return 0;
    }
    return (check(a,b+1,all+a[b],c,n)||check(a,b+1,all xor a[b],c,n));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        int d[a] = {};
        for(int &i : d) {
            cin>>i;
        }
        brk = 0;
        if(check(d,0,b,c,a)) cout<<"Alice";
        else cout<<"Bob";
        cout<<"\n";
    }
    return 0;
}