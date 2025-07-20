// Author : ysh
// 2025/07/18 Fri 21:14:46
// https://www.luogu.com.cn/problem/P2661
#include<bits/stdc++.h>
using namespace std;
#include<slow>
// vc<int>color;
// inline int ff(int x) {
//     if(color.at(x) == x) return x;
//     return color.at(x) = ff(color.at(x));
// }
// void mg(int a, int b) {
//     color.at(ff(a)) = ff(b);
//     return;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;

    repo(&i, f) i--;
    // re(i, n) mg(i, f.at(i));

    int ans = INT_MAX;
    int track = -1;
    vc<bool>mark(n);
    function<int(int, int)> check = [&] (int x, int d) {
        debug(x, d);
        if(mark.at(x)) return track = x, d;
        mark.at(x) = 1;
        int now = check(f.at(x), d + 1);
        if(x == track && now - d > 2) return ans = min(now - d, ans), now;
        else return now;
    };

    re(i, n) if(!mark.at(i)) check(i, 0);

    out(ans);
    return 0;
}