// Author : ysh
// 2026/09/19 Sat 09:14:09
#include<bits/stdc++.h>
using namespace std;
// #include<slow>
#define int int64_t
constexpr int MAX = 1e18;
constexpr int N = __lg(MAX) + 1;
vector<int>pre(N + 1);
inline void init() {
    int last = 1;
    for(int &i : pre) i = last, last = last << 1;
    return;
}
// inline int abs(int x) {
//     return (x < 0 ? -x : x);
// }
inline int check(int x, int n, int p) {
    return abs(n - pre.at(p) - pre.at(x));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cerr<<LLONG_MAX;
    init();
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;

        int now = LLONG_MAX;
        for(int k = 0;k<=N;k++) {
            now = min(check(0, n, k), now);
            for(int i = 0, jump = N;jump != 0;jump--) {
                for(signed j = -1;j <= 1;j = j + 2) {
                    int mid = i + jump * j;
                    if(mid < 0) continue;
    
                    // debug(mid, check(mid, n, k));
                    // if(k == 1 && mid == 3) exit(-1);
                    int p = check(mid, n, k);
                    if(p < now) {
                        now = p;
                    }
                }
            }
            // debug(k, now);
        }

        cout<<now<<"\n";
    }
    return 0;
}