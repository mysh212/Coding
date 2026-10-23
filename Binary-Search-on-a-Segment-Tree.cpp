// Author : ysh
// 2026/10/20 Tue 14:24:06
// https://atcoder.jp/contests/aalc001/tasks/aalc001_c
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>f;

#define left(i) ((i << 1) | 1)
#define right(i) ((i << 1) + 2)

void init(int n) {
    ::n = n;
    f = vector<int>(n << 2);
    return;
}

#define set _set
void set(int x, int v, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;
    if(nl == nr && nl == x) return f.at(t) = v, void();
    if(nl == nr) return;

    if(x < nl || x > nr) return;

    int mid = (nl + nr) >> 1;
    set(x, v, left(t), nl, mid);
    set(x, v, right(t), mid + 1, nr);

    return;
}

int get(int l, int r, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;

    if(l <= nl && nr <= r) return f.at(t);
    if(nr < l || nl > r) return 0;
    
    int mid = (nl + nr) >> 1;
    return get(l, r, left(t), nl, mid) + get(l, r, right(t), mid + 1, nr);
}

pair<int, int> lget(int x, int v, int t = 0, int nl = -1, int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0, nr = n - 1;

    if(nr < x) return {0, -1};

    int mid = (nl + nr) >> 1;
    auto ll = lget(x, v, left(t), nl, mid);

    if(ll.second != mid && ll.second != -1) return ll;

    auto rr = lget(x, v - ll.first, right(t), mid + 1, nr);
    rr.first += ll.first;

    return rr;
}

// pair<int, int> rget(int x, int v, int t = 0, int nl = -1, int nr = -1) {
//     if(nl == -1 && nr == -1) nl = 0, nr = n - 1;

//     if(nr < x) return {0, -1};

//     int mid = (nl + nr) >> 1;
//     auto ll = lget(x, v, left(t), nl, mid);

//     if(ll.second != mid) return ll;

//     auto rr = lget(x, v - ll.first, right(t), mid + 1, nr);
//     rr.first += ll.first;

//     return rr;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;

    init(a);
    for(int i = 0;i<a;i++) set(i, f.at(i));

    while(b--) {
        short op;int a, b;cin>>op>>a>>b;
        if(op == 1) {
            set(a - 1, b);
            continue;
        }
        if(op == 2) {
            cout<<lget(a - 1, b).second<<" ";
            continue;
        }
        if(op == 3) {
            // cout<<rget(a - 1, b).second<<" ";
            continue;
        }
    }
}