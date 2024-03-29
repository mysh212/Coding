// Author : ysh
// 12/15/2022 Thu 19:30:10.17
// https://www.codechef.com/problems/CHEFQUE
#include<bits/stdc++.h>
using namespace std;
bitset<4294967296>f;
long long ans = 0;
void check(long long r) {
    if(!(r & 1)) {
        r = r >> 1;
        if(!f.test(r)) return;
        f.reset(r);
        ans = ans - r;
        return;
    }
    r = r >> 1;
    if(f.test(r)) return;
    f.set(r);
    ans = ans + r;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    long long a,b,c;cin>>a>>b>>c;
    while(n--) {
        check(a);
        a = ((long long) (a * b + c)) & ((1LL << 32) - 1);
    }
    cout<<ans;
    return 0;
}