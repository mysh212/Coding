// Author : ysh
// 03/03/2023 Fri  9:31:38.30
// https://codeforces.com/contest/1796/problem/C
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int R = 998244353;
int check(int l,int r,int v,int b) {
    if(l == r) return l;
    if(l + 1 == r) return (r * v <= b ? r : l);
    int mid = (l + r) >> 1;
    if(mid * v <= b) return check(mid,r,v,b);
    else return check(l,mid - 1,v,b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        cout<<(__lg(b / a)) + 1<<" ";

        int tmp = __lg(b / a);
        long long ans = 0;
        int l = check(a - 1,b,(1 << tmp),b);
        int r = check(a - 1,b,(1 << (tmp - 1)) * 3,b);
        debug(a,b,l,r);
        if(l != a - 1) ans = ans + (l - a + 1),ans = ans % R;
        if(r != a - 1) ans = ans + (tmp * (r - a + 1)),ans = ans % R;
        cout<<ans % R<<"\n";
    }
}