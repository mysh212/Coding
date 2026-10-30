// Author : ysh
// 2026/10/24 Sat 20:17:30
#include<bits/stdc++.h>
using namespace std;
#include<slow>
inline int operator<(const pair<int, long double> a, const pair<int, long double> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
inline pair<int, long double> operator-(pair<int, long double> x) {
    return make_pair(x.first + 1, x.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
// cerr<<(pair<bool, long double>({false, 0.5}) < pair<bool, long double>({true, 0.5}));
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vc<pair<int, int>>f(n);
        repo(&i, f) cin>>i;

        #define _m(i, j, k) make_pair(((k << 1) | (i < 0 ? 1 : 0)), (((long double) j) / (i + 1e-7)))
        #define m(i, j) _m(i.first, i.second, j)

        sort(all(f), [](pair<int, int>&a, pair<int, int>&b) {
            if(a.first < 0 && b.first > 0) return a > b;
            if(b.first < 0 && a.first > 0) return a < b;
            return 1LL * a.second * b.first > 1LL * b.second * a.first;
        });
        re(i, n) f.push_back(f.at(i));
        
        vc<pair<int, long double>> v(n << 1);
        re(i, n) v.at(i) = m(f.at(i), 0), v.at(n + i) = m(f.at(i), 1);
        // debug(v);
        sort(all(v), [](auto l, auto r) {
            return (l.first == r.first ? l.second > r.second : l.first < r.first);
        });
        cerr<<fixed<<setprecision(20);
        repo(&i, v) {
            debug(i);
        }

        #define f v

        int ans = 0;
        int r = 0;
        re(i, n) {
            while(r != (n << 1) && f.at(r) < -f.at(i)) r++;
            debug(i, r);
            ans = max(ans, r - i);
        }

        outl((ans == (n << 1) ? n : ans));
    }
    return 0;
}