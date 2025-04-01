// Author : ysh
// 2025/03/29 Sat 19:58:33
// https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<pair<int,int>>f(n);
    cin>>f;

    int ans = 0;
    int r = 0;
    sort(all(f), [] (pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    });
    repo(&i, f) {
        if(i.first >= r) r = i.second, ans++;
    }

    out(ans);
    return 0;
}