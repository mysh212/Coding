// Author : ysh
// 2026/11/07 Sat 22:54:10
#include<bits/stdc++.h>
using namespace std;
// #define N 26
// const int STEP = __lg(N);
#define STEP 5
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;
    vc<string>f(n);
    cin>>f;

    vc<multiset<int>>s(m * m + 1);

    int mask = (1 << (STEP * m)) - 1;
    vector<int>masks(m);
    re(i, 1, m + 1) masks[i - 1] = ((mask >> (STEP * i)) << (STEP * i)) | (i == 0 ? 0 : ((1 << (STEP * (i - 1))) - 1));
    debug(mask, masks);

    int64_t ans = 0;
    repo(&k, f) {
        int now = 0;
        repo(&i, k) now = (now << STEP) | (i - 'a');
        // debug(masks[0]);
        debug(k, now & masks[0]);
        
        re(i, m) re(j, i + 1) ans += s.at(i * m + j).count(now & masks[i] & masks[j]);
        debug(ans);
        re(i, m) ans -= s.at(i * m + i).count(now & masks[i]) * (m - 1);
        debug(ans);
        ans += s.at(m * m - 1).count(now);
        
        re(i, m) re(j, i + 1) {
            // if(i == j) continue;
            
            s[(i * m + j)].insert(now & masks[i] & masks[j]);
        }
        debug(s);
    }

    out(ans);
    return 0;
}