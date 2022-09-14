// Author : ysh
// 09/14/2022 Wed  8:39:04.05
// https://atcoder.jp/contests/dp/tasks/dp_q
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
struct tree{
    vector<int>f;
    int n;

    tree(int n) {
        this->n = n;
        f.resize(n);
    }

    tree(vector<int>&v):
    tree(v.size()) {
        int t = 0;
        for(int &i : v) {
            add(t++,i);
        }
    }

    void add(int a,int l) {
        for(;a < n;a = (a) | (a + 1)) {
            f.at(a) = max(f.at(a),l);
        }
    }

    int sum(int l) {
        int ans = 0;
        for(;l >= 0;l = (l & (l + 1)) - 1) {
            ans = max(ans,f.at(l));
        }
        return ans;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    int mmax = 0;
    for(int &i : f) {
        cin>>i;
        mmax = max(mmax,i);
    }
    for(int &i : g) {
        cin>>i;
    }
    // vector<int>mark(mmax + 1);
    tree t((mmax + 1));
    vector<int>r(mmax + 1);
    int a,b;
    for(int i = 0;i<n;i++) {
        int tmp = r.at(f.at(i));
        int mmax = t.sum(f.at(i) - 1);
        if(mmax + g.at(i) > tmp) {
            t.add(f.at(i),mmax - tmp + g.at(i));
            r.at(f.at(i)) += mmax - tmp + g.at(i);
        }
    }
    cout<<t.sum(mmax);
    return 0;
}