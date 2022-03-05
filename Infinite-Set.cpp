// Author : ysh
// 02/20/2022 Sun 23:16:37.68
// https://codeforces.com/contest/1635/problem/D
// WA
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int>f;
    map<int,bool>d;
    int n,p;cin>>n>>p;
    const int mmax = 1<<p;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        f.push(tmp);
    }
    while(!f.empty()) {
        int now = f.front();
        if(now > mmax) {
            f.pop();
            continue;
        }
        f.push(now * 2 + 1);
        f.push(now * 4);
        d[now] = 1;
        f.pop();
    }
    int ans = 0;
    for(auto i : d) {
        ans++;
        ans = ans % 10000007;
    }
    cout<<ans;
    return 0;
}