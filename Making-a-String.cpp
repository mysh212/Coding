// Author : ysh
// 2024/11/06 Wed 23:26:28
// https://codeforces.com/contest/624/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    sort(f.rbegin(),f.rend());
    long long ans = 0;
    int last = f[0] + 1;
    for(int &i : f) {
        if(last == 0) break;
        ans = ans + (last = min(last - 1, i));
    }
    cout<<ans;
    return 0;
}