// Author : ysh
// 2025/03/12 Wed 23:34:56
#include<bits/stdc++.h>
using namespace std;
// #define cout cerr
#include<slow>
// #include<fast>
#include<mint>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("testbench.txt", "r", stdin);
    // freopen("HW1_E24124723.txt", "w", stdout);

    string a,b;
    while(cin>>a>>b) {
        mint l,r;
        l = mint(a);
        r = mint(b);
        outl(l + r);
        outl(l - r);
        outl(l * r);
        outl(l / r);
        nl;
    }
    return 0;
}