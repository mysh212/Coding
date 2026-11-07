// Author : ysh
// 2026/11/07 Sat 23:33:36
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
// #include<fast>
#include<slow>
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;
    vector<string>f(n);
    for(string &i : f) cin>>i;

    int64_t ans[3] = {};

    gp_hash_table<string, int>s;
    repo(&i, f) ans[0] += s[i]++;

    re(i, m) {
        // map<int>s;
        s = gp_hash_table<string, int>();

        repo(&k, f) {
            string now = "";

            re(o, m) if(i != o) now += k[o];

            ans[1] += s[now]++;

            // s[now]++;
            debug(ans[1]);
        }
    }

    re(i, m) re(j, i) {
        // if(i == j) continue;

        s = gp_hash_table<string, int>();
        repo(&k, f) {
            string now = "";
            re(o, m) if(!(o == i || o == j)) now += k[o];

            ans[2] += s[now]++;

            // s[now]++;
        }
    }

    // re(i, 3) outs(ans[i]);nl;

    ans[1] = ans[1] - ans[0] * m;
    ans[2] = ans[2] - ans[0] * ((m * (m - 1)) >> 1);

    ans[2] = ans[2] - ans[1] * (m - 1);
    out(ans[2] + ans[1] + ans[0]);
    return 0;
}