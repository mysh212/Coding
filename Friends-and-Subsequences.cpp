// Author : ysh
// 2025/06/27 Fri 00:02:39
// https://codeforces.com/contest/689/problem/D
#include<bits/stdc++.h>
using namespace std;
#include<table>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n), g(n);
    cin>>f>>g;

    table<int>t(f, (function<int(int, int)>) ([] (int a, int b) {
        return max(a, b);
    })), v(g);

    auto check = [&] (auto self, int l, int r, int ll = -1) {
        if(ll == -1) ll = l;
        if(l == r) return l;

        int mid = (l + r) >> 1;
        if(t.get(ll, mid) >= v.get(ll, mid)) return self(self, l, mid, ll);
        else return self(self, mid + 1, r, ll);
    };

    auto ck = [&] (auto self, int l, int r, int ll = -1) {
        if(ll == -1) ll = l;
        if(l + 1 == r) return l;

        int mid = (l + r) >> 1;
        if(t.get(ll, mid) <= v.get(ll, mid)) return self(self, mid, r, ll);
        else return self(self, l, mid, ll);
    };

    long long ans = 0;
    re(i, n) {
        // outt(|);
        if(f.at(i) > g.at(i)) continue;
        int r = ck(ck, i, n, i);
        int l = check(check, i, n, i);
        if(l == n) continue;
        if(r - l + 1 >= 0) ans += (r - l) + 1;
        debug(i, l, r);
    }

    out(ans);
    // debug(ans);
    // re(i, n) re(j, i, n) if(t.get(i, j) == v.get(i, j)) ans--;
    // debug(ans);
    // assert(ans == 0);
    return 0;
}