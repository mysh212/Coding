// Author : ysh
// 2026/11/08 Sun 03:14:31
#include<bits/stdc++.h>
// #include<ranges>
using namespace std;
const int N = int(5e5);
constexpr int R = 700; // sqrt
#include<slow>
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<pair<int, int>>f(n);
    cin>>f;

    int t = 0;
    int q;cin>>q;
    vc<pair<int, int>>qs(q);
    for(auto &i : qs) cin>>i.first, i.second = t++;

    sort(all(qs));
    int k = qs.back().first;
    
    vc<vc<int>>cheat(R);
    vc<int>op(k + 1);
    for(auto &[l, r] : f) {
        if(r >= R) for(int i = r - l; i <= k; i += r) op[i] = op[i] - r;
        else {
            if(cheat.at(r).empty()) cheat.at(r) = vector<int>(r + 1);
            cheat.at(r).at(r - l)++;
            cheat.at(r).at(0)++;
            n--;
        }
    }

    re(i, 10) {debug(cheat[3][i]);}
    re(i, R) {
        if(cheat.at(i).empty()) continue;

        int last = 0;
        int sig = cheat.at(i)[0];
        re(j, 1, i + 1) {
            cheat.at(i).at(j) = last += sig + (-i * cheat.at(i).at(j));
        }

        cheat[i][0] = 0;
    }
    re(i, 10) {debug(i, cheat[3][i]);}

    vc<int>aans(q);

    debug(n);

    // sort(all(op));
    // int os = op.size();

    int r = 0;
    int ans = 0;
    int last = 0;
    repo(&i, f) ans += i.first;
    for(auto &[i, d] : qs) {
        ans += n * (i - last);
        
        while(r != k + 1 && r <= i) ans = ans + op.at(r++);

        debug(ans);
        int t = ans;
        
        re(j, 1, R) if(!cheat.at(j).empty()) t += cheat.at(j).at(i % j);
        
        debug(r);
        
        aans[d] = t;
        last = i;
    }

    repo(&i, aans) outl(i);
    return 0;
}