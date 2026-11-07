// Author : ysh
// 2026/11/07 Sat 20:54:50
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    int64_t ans = accumulate(all(f), 0LL);
    if(ans < 0) repo(&i, f) i = -i;
    
    int l, r;l = r = 0;
    repo(&i, f) if(i > 0) l = max(l, i);
    repo(&i, f) if(i < 0) r = max(r, -i);

    int ll, rr;ll = rr = 0;
    repo(&i, f) if(i > 0) ll += i;
    repo(&i, f) if(i < 0) rr += i;

    out(max({ll - l, rr + l, ll + r, rr - r}) + 1);
    return 0;
}