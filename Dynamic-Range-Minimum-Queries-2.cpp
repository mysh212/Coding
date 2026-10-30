// Author : ysh
// 2026/10/30 Fri 15:36:33
// https://cses.fi/problemset/task/1649
#include<bits/stdc++.h>
using namespace std;
#include<slow>

int n;
vector<int>f;

#define left(i) ((i << 1) | 1)
#define right(i) ((i << 1) + 2)

#undef nl

inline void pull(int t, int l, int r) {
    if(l == r) return;
    f.at(t) = min(f.at(left(t)), f.at(right(t)));

    return;
}

#define set _set
inline void set(int x, int v, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    if(nl == nr && nl == x) return f.at(t) = v, void();

    if(x < nl || x > nr) return;

    int mid = (nl + nr) >> 1;
    set(x, v, left(t), nl, mid);
    set(x, v, right(t), mid + 1, nr);

    pull(t, nl, nr);

    return;
}

inline int get(int l, int r, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    
    if(r < nl || l > nr) return INT_MAX;
    if(l <= nl && nr <= r) return f.at(t);

    int mid = (nl + nr) >> 1;
    return min(get(l, r, left(t), nl, mid), get(l, r, right(t), mid + 1, nr));
}

inline void init(vector<int>&f) {
    n = f.size();
    ::f = vector<int>(n << 2);

    re(i, n) set(i, f.at(i));

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<int>f(a);
    cin>>f;

    init(f);
    debug(::f);

    re(b) {
        short op;cin>>op;
        if(op == 1) {
            int a, b;cin>>a>>b;
            set(a - 1, b);
        }
        if(op == 2) {
            int l, r;cin>>l>>r;
            outl(get(l - 1, r - 1));
        }
    }
    return 0;
}