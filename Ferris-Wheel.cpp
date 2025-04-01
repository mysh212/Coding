// Author : ysh
// 2025/03/29 Sat 19:13:34
// https://cses.fi/problemset/task/1090
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<int>f(a);
    cin>>f;
    
    multiset<int, greater<int>>s(all(f));
    int ans = 0;
    while(!s.empty()) {
        int t = b;
        auto now = s.begin();
        for(int i = 0; i<=1 && now != s.end();i++) {
            t = t - *now;
            s.erase(now);
            now = s.lower_bound(t);
        }
        ans++;
    }

    out(ans);
    return 0;
}