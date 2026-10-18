// Author : ysh
// 2026/10/17 Sat 21:32:40
// https://atcoder.jp/contests/aalc001/tasks/aalc001_a
#include<bits/stdc++.h>
using namespace std;
#include<slow>
vc<int>f;
int n;

inline void init(int n) {
    ::n = n;
    f = vc<int>(n << 2);
}

#define left(i) ((i << 1) | 1)
#define right(i) ((i << 1) + 2)

#undef nl
int get(int l, int r, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    
    if(nl > r || nr < l) return INT_MAX;
    if(nl >= l && nr <= r) return f.at(t);

    int mid = (nl + nr) >> 1;
    return min(get(l, r, left(t), nl, mid), get(l, r, right(t), mid + 1, nr));
}

#define set _set
void set(int x, int v, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    if(nl == nr && nl == x) return f.at(t) = v, void();

    if(x < nl || x > nr) return;

    int mid = (nl + nr) >> 1;
    set(x, v, left(t), nl, mid);
    set(x, v, right(t), mid + 1, nr);

    f.at(t) = min(f.at(left(t)), f.at(right(t)));

    return;
}

void dddebug() {
    return;
    re(i, n) outs(get(i, i));
    out("\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<int>f(a);
    cin>>f;

    init(a);

    re(i, n) set(i, f.at(i));

    re(b) {
        short op;cin>>op;

        if(op == 1) {
            int a, b;cin>>a>>b;
            set(a - 1, b);
        } else {
            int a, b;cin>>a>>b;
            outl(get(a - 1, b - 1));
        }
        dddebug();
    }

    return 0;
}