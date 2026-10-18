// Author : ysh
// 2026/10/17 Sat 22:54:23
// https://atcoder.jp/contests/aalc001/tasks/aalc001_b
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define int int64_t
#undef INT_MAX
#define INT_MAX LLONG_MAX

vc<int>f, lazy;
int n;

inline void init(int n) {
    ::n = n;
    f = vc<int>(n << 2);
    lazy = vc<int>(n << 2);
}

#define left(i) ((i << 1) | 1)
#define right(i) ((i << 1) + 2)

inline void pull(int t, int l, int r) {
    if(l == r) return;

    f.at(t) = min(f.at(left(t)), f.at(right(t)));
    return;
}

inline void push(int t, int l, int r) {
    if(l == r || lazy.at(t) == 0) return;

    lazy.at(left(t)) += lazy.at(t);
    lazy.at(right(t)) += lazy.at(t);

    // f.at(left(t)) = f.at(right(t)) = lazy.at(t);
    f.at(left(t)) += lazy.at(t);
    f.at(right(t)) += lazy.at(t);

    lazy.at(t) = 0;
    return;
}

#undef nl
int get(int l, int r, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;

    push(t, nl, nr);
    
    if(nl > r || nr < l) return INT_MAX;
    if(nl >= l && nr <= r) return f.at(t);

    int mid = (nl + nr) >> 1;
    return min(get(l, r, left(t), nl, mid), get(l, r, right(t), mid + 1, nr));
}

// #define set _set
void add(int l, int r, int v, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    // if(nl == nr && nl == x) return f.at(t) = v, void();

    push(t, nl, nr);

    if(nl > r || nr < l) return;
    if(l <= nl && nr <= r) return lazy.at(t) += v, f.at(t) += v, void();

    int mid = (nl + nr) >> 1;
    add(l, r, v, left(t), nl, mid);
    add(l, r, v, right(t), mid + 1, nr);

    // f.at(t) = min(f.at(left(t)), f.at(right(t)));
    pull(t, nl, nr);

    return;
}

void dddebug() {
    re(i, n) outs(get(i, i));
    out("\n");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;cin>>n>>k;
    init(n);
    vc<int>f(n);
    cin>>f;

    re(i, n) add(i, i, f.at(i));

    re(k) {
        short op;cin>>op;

        if(op == 1) {
            int l, r, v;cin>>l>>r>>v;
            add(l - 1, r - 1, v);
        } else {
            int l, r;cin>>l>>r;
            outl(get(l - 1, r - 1));
        }
        // dddebug();
    }

    return 0;
}