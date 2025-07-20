// Author : ysh
// 2025/07/18 Fri 21:47:02
// https://www.luogu.com.cn/problem/P3390
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#include<square>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t a,b;cin>>a>>b;

    if(b == 0) {
        re(i, a) {re(j, a) outs((i == j ? 1 : 0)); nl;}
        return 0;
    }

    vc<vc<long long>>f(a, vc<long long>(a));
    cin>>f;

    t<long long>sq(f);
    sq.mod(int(1e9) + 7);

    repo(&i, (sq ^ b).f) outl(i);

    return 0;
}