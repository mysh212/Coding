// Author : ysh
// 2026/10/31 Sat 19:01:18
#include<bits/stdc++.h>
using namespace std;
#include<slow>

struct Edge {
    int u, v, w;
    inline friend istream& operator>>(istream& in, Edge &x) {
        in>>x.u>>x.v>>x.w;
        return in;
    }
};

std::vector<int> mst_edge_queries(int n, const std::vector<Edge> &edges, const std::vector<std::vector<int>> &queries) {
// Author : ysh
// 2026/10/31 Sat 19:01:18
struct mgr {
    int n;
    vector<int>color;
    vector<int>mark;

    mgr(int n = 0):
        n(n), color(n) {
            iota(color.begin(), color.end(), 0);
        };

    inline int ff(int x) {
        if(color.at(x) == x) return x;
        return color.at(x) = ff(color.at(x));
    }

    inline void rollback() {
        for(auto &i : mark) color.at(i) = i;
        return;
    }

    inline void mg(int a, int b) {
        return mark.push_back(ff(a)), color.at(ff(a)) = ff(b), void();
    }
};
    int a, b;a = n, b = edges.size();

    // color = _color = vector<int>(a);
    // iota(color.begin(), color.end(), 0);
    // iota(_color.begin(), _color.end(), 0);

    mgr mgrrr(b);

    int t = 0;
    vector<array<int, 4>>f(b);
    // for(auto &i : f) cin>>i[0]>>i[1]>>i[2], i[0]--, i[1]--, i[3] = t++;
    for(int i = 0;i<b;i++) f.at(i) = {edges.at(i).u - 1, edges.at(i).v - 1, edges.at(i).w, t++};

    vector<vector<array<int, 3>>>v(a);
    for(auto &[l, r, t, d] : f) v.at(l).push_back({r, t, d}), v.at(r).push_back({l, t, d});

    vector<int>mark(a, INT_MAX), mk(a);
    vector<bool>ok(b);
    using T = array<int, 4>;
    priority_queue<T, vector<T>, greater<T>>q;
    q.push({0, -1, 0, -1});
    while(!q.empty()) {
        auto [l, x, y, k] = q.top(); q.pop();

        if(mark.at(y) < l) continue;
        if(k != -1) ok.at(k) = 1;
        if(mark.at(y) == l) {
            mgrrr.mg(mk.at(y), k);
            continue;
        }
        mark.at(y) = l;
        mk.at(y) = k;

        #undef nl
        for(auto &[nd, nl, nk] : v.at(y)) {
            if(nd == x) continue;
            q.push({nl, y, nd, nk});
        }
    }
    debug(ok);
    debug(mark);
    re(i, b) mgrrr.ff(i);
    debug(mgrrr.color);

    vector<int>aans;
    mgr tp(a);
    for(auto &i : queries) {
        int ans = 0;

        tp.rollback();
        for(auto n : i) {
            n--;

            if(!ok.at(n)) continue;
            if(tp.ff(f.at(n)[0]) == tp.ff(f.at(n)[1])) continue;

            ans++;
            tp.mg(f.at(n)[0], f.at(n)[1]);
            // s.insert(mgrrr.ff(n));
        }
        aans.push_back(ans);
    }
    return aans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vector<Edge>f(b);
    for(auto &i : f) cin>>i;

    int q;cin>>q;
    vector<vector<int>>qq(q);
    for(auto &i : qq) {
        int n;cin>>n;
        while(n--) {
            int n;cin>>n;
            i.push_back(n);
        }
    }

    for(int &i : mst_edge_queries(a, f, qq)) cout<<i<<"\n";
    return 0;
}