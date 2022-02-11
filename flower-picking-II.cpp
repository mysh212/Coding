// Author : ysh
// 02/11/2022 Fri 20:02:21.83
// http://choj.me/problem/00008
#include<bits/stdc++.h>
using namespace std;
int mmax = 0;
bool b = 0;
void check(int* a,int n,int sig,int end,int k) {
    if(b) return;
    if(sig == k) {
        mmax = k;
        return;
    }
    if(n == end) return;
    if(sig + a[n] <= k) {
        mmax = max(mmax,sig + a[n]);
        check(a,n+1,sig + a[n],end,k);
        check(a,n+1,sig,end,k);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int k;cin>>k;
    int a[n] = {};
    for(int &i : a) {
        cin>>i;
    }
    sort(a,a+n);
    check(a,0,0,n,k);
    cout<<mmax;
    return 0;
}