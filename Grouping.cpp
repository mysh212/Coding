// Author : ysh
// 02/20/2023 Mon 16:20:23.89
// https://atcoder.jp/contests/dp/tasks/dp_u
#include<bits/stdc++.h>
#include<fast>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    for(auto &i : f) for(int &j : i) cin>>j;
    // bitset<16>all;
    // all.reset();
    vector<long long>mk(1 << n,-1);
    vector<long long>mark(1 << n,-1);   

    function<long long(int)> check = [&] (int now) {
        if(now == 0) return 0LL;
        if(mark.at(now) != -1) return mark.at(now);
        // cerr<<bitset<4>(now)<<"\n";
        long long mmax = LONG_LONG_MIN;
        for(int i = now;i > 0;i = (i - 1) & now) {
            // cerr<<bitset<4>(i)<<"\n";
            if(mk.at(i) == -1) {
                mk.at(i) = 0;
                for(int j = 0;j<n;j++) {
                    if(!(i & (1 << j))) continue;
                    for(int k = j + 1;k < n;k++) {
                        if(i & (1 << k)) mk.at(i) += f.at(j).at(k);
                    }
                }
            }
            mmax = max(mmax,mk.at(i) + check(now ^ i));
        }
        return mark.at(now) = mmax;
    };

    cout<<check((1 << n) - 1);
    // cerr<<"\n";
    // for(int i = 0;i < (1 << n);i++) {
    //     cerr<<bitset<4>(i)<<" "<<mark.at(i)<<"\n";
    // }
    return 0;
}