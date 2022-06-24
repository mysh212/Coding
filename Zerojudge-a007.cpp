// Author : ysh
// 06/18/2022 Sat 13:57:32.20
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// #define int long long
inline bool isprime(int);
constexpr int MAX = 50000;
vector<bool>s(MAX + 1);
vector<int>f;
inline int ff(int x) {
    return (((x >> 1) * 6)) + (x & 1 ? 5 : 1);
    //1 --> 0
    //5 --> 1
}
inline int g(int x) {
    return (x / 6) << 1 + (x % 6 == 1 ? 0 : 1);
    //1 --> 0
    //5 --> 1
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    clock_t t = clock();
    s[0] = s[1] = 1;
    f.push_back(2);
    int tmp = (int) sqrt(MAX) + 1;
    for(int i = 2;i <= MAX;i++) {
        if(!s[ff(i)]) {
            f.push_back(ff(i));
            if(i > tmp) continue;
            int len = f.size();
            for(int j = 0;j <= len;j++) {
                s[g(f[j] * ff(i))] = true;
                if(ff(i) % f[j] == 0) break;
                // debug(i,j);
            }
        }
    }
    // for(int i = MAX + 1;i<INT_MAX;i++) {
    //     if(!(i & 1)) continue;
    //     if(i % 3 == 0) continue;
    //     if(i % 5 == 0) continue;
    //     if(isprime(i)) f.push_back(i);
    // }
    int n;
    while(cin>>n) {
        cout<<(isprime(n) ? "質數\n" : "非質數\n");
    }
    cerr<<clock() - t;
    return 0;
}
inline bool isprime(int x) {
    if(x != 2 && !(x & 1)) return 0;
    if(not (x % 6 == 1 || x % 6 == 5)) return 0;
    x = g(x);
    if(x <= MAX) {
        return !s[x];
    }
    int now = (int) sqrt(x) + 1;
    for(int i : f) {
        if(i > now) return 1;
        if(x % i == 0) return 0;
    }
    return 1;
}