// Author : ysh
// 10/04/2022 Tue 11:22:32.35
// https://atcoder.jp/contests/dp/tasks/dp_a
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
        if(i >= 2) g[i] = min(g[i - 1] + abs(f[i - 1] - f[i]),g[i - 2] + abs(f[i - 2] - f[i]));
        if(i == 1) g[i] = abs(f[1] - f[0]);
    }
    // for(int i : g) cerr<<i<<" ";
    cout<<g[n - 1];
    return 0;
}