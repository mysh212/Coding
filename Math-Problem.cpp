// Author : ysh
// 02/07/2023 Tue 15:35:30.34
// https://codeforces.com/group/H0qY3QmnOW/contest/425166/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
#define check(i) (a / i == b)
int ck(int l,int r) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(l,mid);
    return ck(mid + 1,r);
}
int cku(int l,int r) {
    // cerr<<l<<" "<<r<<"\n";
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return cku(mid,r);
    return cku(l,mid);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    if(b > a) {
        cout<<"0";
        return 0;
    }
    // cout<<cku(a / b,(int) (1e18) + 1) - ck(1,a / b) + 1;
    int left = (a / b);
    int right = (a / (b + 1)) + 1;
    if(left >= right) cout<<left - right + 1;
    else cout<<0;
    return 0;
}