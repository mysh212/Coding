// Author : ysh
// 2025/06/27 Fri 00:42:06
// https://codeforces.com/contest/689/problem/D
// TLE
#include<bits/stdc++.h>
using namespace std;
struct tree{
    int n;
    vector<int>f;

    tree(vector<int>f):
        f(f.size()), n(f.size()) {
            int t = 0;
            for(int &i : f) add(t++, i);
        };

    int get(int l, int r) {
        return get(r) - (l == 0 ? 0 : get(l - 1));
    }

    int get(int x) {
        int ans = 0;
        for(;x>=0;x = (x & (x + 1)) - 1) ans += f.at(x);
        return ans;
    }

    void add(int x, int v) {
        for(;x < n;x = x | (x + 1)) f.at(x) += v;
    }
};
template<int V, class K>
struct seg_tree{
    int n;
    vector<int>f;

    #define left(i) ((i << 1) | 1)
    #define right(i) ((i << 1) + 2)

    #define update(i) (f.at(i) = (K()(f.at(right(i)), f.at(left(i))) ? f.at(right(i)) : f.at(left(i))))

    seg_tree(int n):
        f(n << 2), n(n) {};

    seg_tree(vector<int>f):
        seg_tree(f.size()) {
            init(f);
        }

    void init(vector<int>&v, int l = -1, int r = -1, int t = 0) {
        if(l == -1 && r == -1) l = 0, r = n - 1;

        if(l == r) return f.at(t) = v.at(l), void();
        int mid = (l + r) >> 1;

        init(v, l, mid, left(t));
        init(v, mid + 1, r, right(t));

        update(t);
        return;
    }

    void set(int x, int v, int l = -1, int r = -1, int t = 0) {
        if(l == -1 && r == -1) l = 0, r = n - 1;

        if(l == r) return f.at(t) = v, void();
        int mid = (l + r) >> 1;

        if(x <= mid) set(x, v, l, mid, left(t));
        else set(x, v, mid + 1, r, right(t));

        update(t);
        return;
    }

    int sum(int l, int r, int nl = -1, int nr = -1, int t = 0) {
        if(nl == -1 && nr == -1) nl = 0, nr = n - 1;

        if(nl >= l && nr <= r) return f.at(t);
        if(nl > r || nr < l) return V;

        int mid = (nl + nr) >> 1;

        int ll = sum(l, r, nl, mid, left(t));
        int rr = sum(l, r, mid + 1, nr, right(t));
        
        return (K()(ll, rr) ? ll : rr);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n), g(n);
    for(int &i : f) cin>>i;
    for(int &j : g) cin>>j;

    seg_tree<INT_MIN, greater<int>>t(f);
    seg_tree<INT_MAX, less<int>>v(g);

    auto check = [&] (auto self, int l, int r, int ll = -1) {
        if(ll == -1) ll = l;
        if(l == r) return l;

        int mid = (l + r) >> 1;
        if(t.sum(ll, mid) >= v.sum(ll, mid)) return self(self, l, mid, ll);
        else return self(self, mid + 1, r, ll);
    };

    auto ck = [&] (auto self, int l, int r, int ll = -1) {
        if(ll == -1) ll = l;
        if(l + 1 == r) return l;

        int mid = (l + r) >> 1;
        if(t.sum(ll, mid) <= v.sum(ll, mid)) return self(self, mid, r, ll);
        else return self(self, l, mid, ll);
    };

    long long ans = 0;
    for(int i = 0;i<n;i++) {
        // outt(|);
        if(f.at(i) > g.at(i)) continue;
        int r = ck(ck, i, n, i);
        int l = check(check, i, n, i);
        if(l == n) continue;
        if(r - l + 1 >= 0) ans += (r - l) + 1;
        // debug(i, l, r);
    }

    // out(ans);
    cout<<ans<<"\n";
    // debug(ans);
    // re(i, n) re(j, i, n) if(t.get(i, j) == v.get(i, j)) ans--;
    // debug(ans);
    // assert(ans == 0);
    return 0;
}