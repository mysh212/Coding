// Author : ysh
// 2025/05/21 Wed 00:39:55
// https://vjudge.net/problem/UVA-1234
#include<bits/stdc++.h>
using namespace std;
#include<slow>
vc<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
inline void mg(int a, int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vc<array<int,3>>f(b);
        int pre = 0;
        for(auto &i : f) cin>>i[0]>>i[1]>>i[2], i[0]--, i[1]--, pre += i[2];

        color = vc<int>(a);
        iota(all(color), 0);

        sort(rall(f), [] (array<int,3> a, array<int,3>b) {
            return a[2] < b[2];
        });

        int ans = 0;
        repo(&i, f) if(ff(i[0]) != ff(i[1])) mg(i[0], i[1]), ans += i[2];

        outl(pre - ans);
    }
    return 0;
}