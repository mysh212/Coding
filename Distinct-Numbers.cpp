// Author : ysh
// 2025/03/29 Sat 18:55:24
// https://cses.fi/problemset/task/1621
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
    out(int(unique(all(f)) - f.begin()));
    return 0;
}