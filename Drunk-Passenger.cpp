// Author : ysh
// 2023/09/03 Sun 15:05:07
// https://codeforces.com/gym/103373/problem/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<long double>mark;
long double check(int x,int n,long double now = 1) {
    if(x == n) return now;
    if(mark.at(x) != INFINITY) return mark.at(x);
    long double ans = 0;
    for(int i = x + 1;i<=n;i++) {
        ans = ans + check(i,n,now * ((1.0) / (x == 1 ? (n - x) : (n - x + 1))));
    }
    return mark.at(x) = ans + now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mark = vector<long double>(n,INFINITY);
    cout<<check(1,n) - 1;
    debug(mark);
    return 0;
}