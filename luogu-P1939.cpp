// Author : ysh
// 2025/07/18 Fri 21:53:35
// https://www.luogu.com.cn/problem/P1939
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#include<square>
#define int int64_t
const int R = int(1e9) + 7;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vc<vc<int>>r({{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}), l({{0, 1, 0}, {0, 0, 1}, {1, 0, 1}});

    t<int>ll(l), rr(r);

    ll.mod(R);
    rr.mod(R);

    int n;cin>>n;
    re(n) {
        int n;cin>>n;
        if(n <= 3) outl(1);
        else outl(((ll ^ (n - 3)) * rr).f.at(2).at(0));
    }
    return 0;
}