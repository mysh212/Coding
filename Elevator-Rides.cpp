// Author : ysh
// 02/23/2023 Thu 14:24:53.42
// https://cses.fi/problemset/task/1653
// TLE
#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;
    vector<int>mark(1 << a,-1);
    vector<long long>mk(1 << a,-1);

    function<int(int)> check = [&] (int now) {
        if(now == 0) return 0;
        if(mark.at(now) != -1) return mark.at(now);
        int ans = INT_MAX;
        for(int i = now;i > 0;i = (i - 1) & now) {
            if(mk.at(i) == -1) {
                mk.at(i) = 0;
                for(int j = 0;j < a;j++) {
                    if(i & (1 << j)) mk.at(i) = mk.at(i) + f.at(j);
                }
            }
            if(mk.at(i) > b) continue;
            ans = min(check(now ^ i) + 1,ans);
        }
        return mark.at(now) = ans;
    };
    
    cout<<check((1 << a) - 1);
    return 0;
}