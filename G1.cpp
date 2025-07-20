// Author : ysh
// 2025/06/20 Fri 18:46:59
// https://atcoder.jp/contests/abc410/tasks/abc410_a
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    sort(all(f));
    cin>>n;
    
    out(f.end() - lower_bound(all(f), n));
    return 0;
}