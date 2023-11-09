// Author : ysh
// 2023/08/24 Thu 00:22:22
// https://codeforces.com/contest/1548/problem/B
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#include<fast>
// #define int int64_t
struct seg_tree{
    vector<int64_t>f;
    int n;
    int tmp;
    #define left(i) ((i << 1))
    #define right(i) ((i << 1) | 1)

    seg_tree(int n):
        f(n << 2), n(n) {};
    
    seg_tree(vector<int64_t>&v) {
        n = v.size();
        f.resize(n << 2);
        mt(v);
    }

    void mt(vector<int64_t>&v,int t = 1,int l = -1,int r = -1) {
        debug(l,r);
        if(l == -1 && r == -1) l = 0,r = n - 1;
        if(l == r) return f.at(t) = abs(v.at(l)),void();
        int mid = (l + r) >> 1;
        mt(v,left(t),l,mid);
        mt(v,right(t),mid + 1,r);
        f.at(t) = __gcd(f.at(left(t)),f.at(right(t)));
        return;
    }

    int64_t check(int l,int64_t v,int t = 1,int nl = -1,int nr = -1) {
        debug(nl,nr,v);
        if(nl == -1 && nr == -1) tmp = 0,nl = 0,nr = n - 1;
        if(v == 1) return 1;
        int mid = (nl + nr) >> 1;
        if(nl >= l && __gcd(f.at(t),v) != 1) return tmp = max(tmp,nr - l + 1),__gcd(f.at(t),v);
        if(nr < l) return -1;
        if(nl == nr) return 1;

        debug(nl,nr);
        int64_t ll = check(l,v,left(t),nl,mid);
        if(ll == 1) return 1;
        int64_t rr = check(l,(ll == -1 ? v : ll),right(t),mid + 1,nr);
        debug(l,nl,v,nr,rr);
        return rr;
    }
};
int ck(vector<int64_t>&g) {
    seg_tree t(g);
    int ans = 0;
    for(int i = 0,len = g.size();i<len;i++) {
        t.check(i,g.at(i));
        ans = max(ans,t.tmp);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int64_t>f(n);
        vector<int64_t>g;
        for(int64_t &i : f) {
            cin>>i;
        }
        if(n == 1) {
            cout<<"1 ";
            continue;
        }

        for(int i = 1;i<n;i++) {
            g.push_back(abs(f.at(i) - f.at(i - 1)));
        }

        debug(g);
        cout<<ck(g) + 1<<" ";
    }
    return 0;
}