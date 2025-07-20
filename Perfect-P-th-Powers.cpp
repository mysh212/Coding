// Author : ysh
// 2025/04/23 Wed 13:07:44
// https://vjudge.net/problem/UVA-10622
#include<bits/stdc++.h>
using namespace std;
#include<slow>
// int R = pow((long double) INT_MAX, 1 / 3) + 10;
#define int int64_t
#define R 2000
vc<vc<int>>mark(R);
map<int, int>m;
#define INT_MAX UINT32_MAX
inline void init() {
    re(i, 2, R) {
        long long now = i;
        re(2) if(now * i <= INT_MAX) now *= i;
        do {
            mark.at(i).push_back(now);
        } while((now *= i) <= INT_MAX);
    }
    repo(&i, mark) {
        int t = 3;
        repo(&j, i) {
            auto found = m.find(j);
            if(found == m.end()) m.insert({j, t});
            else if(found->second < t) found->second = t;
            t++;
        }
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;
    while(cin>>n && n != 0) {
        bool neg = n < 0;
        n = abs(n);

        auto found = m.find(n);
        if(found != m.end()) goto yes;
        goto no;
        
        yes:
            if(neg) {
                int now = found -> second;
                while(now != 0 && !(now & 1)) now = now >> 1;
                if(now == 0) outl(1);
                else outl(now);
                continue;
            }

            outl(found -> second);
            continue;
        
        no:
            int p = sqrt(n);
            if(!neg && p * p == n) outl(2);
            else outl(1);
    }
    return 0;
}