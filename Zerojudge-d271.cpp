// Author : ysh
// 2025/04/12 Sat 21:41:38
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 1001
int fp(uint64_t a,uint64_t b,uint64_t c) {
    if(b == 0) return 1;

    int now = fp(a, b >> 1, c);
    now = (now * now) % c;

    if(b & 1) return (now * a) % c;
    return now;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vc<vc<int>>mark(R, vc<int>({0, 1}));
    vc<int>mk(R);
    re(i, 2, R) {
        for(int j = 2;;j++) {
            int ans = (mark.at(i).at(j - 2) + mark.at(i).at(j - 1)) % i;
            if(mark.at(i).at(j - 1) == 1 && ans == 0) break;
            mark.at(i).push_back(ans);
        }
        mk.at(i) = mark.at(i).size();
    }

    int n;cin>>n;
    re(n) {
        uint64_t a,b,c;cin>>a>>b>>c;
        // a = a % mk.at(c);
        
        if(c <= 1) outl(0);
        else outl(mark.at(c).at(fp(a % mk.at(c),b,mk.at(c))));
    }
    return 0;
}