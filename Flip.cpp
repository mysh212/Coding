// Author : ysh
// 2023/09/09 Sat 17:53:08
// https://codeforces.com/gym/103373/problem/F
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int l,r;
    int ll,lr;
    int mmax;
    int now;
    int n;
    explicit box(int l = 0,int r = 0,int nl = 0,int nr = 0,int mmax = 0,int now = 1,int n = 1):
        l(l), r(r), ll(nl), lr(nr), mmax(mmax), now(now), n(n) {};

    box operator+(box &a) {
        box tmp;
        tmp.l = l;
        tmp.r = a.r;
        tmp.ll = (ll == n && r != a.l ? ll + a.ll : ll);
        tmp.lr = (a.lr == a.n && r != a.l ? lr + a.lr : a.lr);
        tmp.n = n + a.n;
        tmp.now = (r != a.l ? now + a.now + ((r + a.l) * (r + a.l + 1)) >> 1 : now + a.now);
        // tmp.mmax = max({a.mmax,mmax,(r == a.l ? INT_MIN : lr + a.ll)});
        // debug(l,r,ll,lr,n,now,mmax);
        return tmp;
    }
    box operator~() {
        return box(!l,!r,ll,lr,mmax,now,n);
    }
    box operator^(bool c) {
        return (c ? *this : box(!l,!r,ll,lr,mmax,now,n));
    }
};
struct seg_tree{
    #define left(i) ((i << 1))
    #define right(i) ((i << 1) | 1)

    vector<box>f;
    vector<bool>hold;
    int n;

    seg_tree(int n) {
        f = vector<box>(n << 2);
        hold = vector<bool>(n << 2);
        this->n = n;
    }

    seg_tree(vector<bool>&v):
        seg_tree(v.size()) {
            mt(v);
        }

    void mt(vector<bool>&v,int t = 1,int l = -1,int r = -1) {
        if( l == -1 && r == -1) l = 0,r = n - 1;
        if(l == r) return f.at(t) = box(int(v.at(l)),int(v.at(r)),1,1,1),void();
        int mid = (l + r) >> 1;
        mt(v,left(t),l,mid);
        mt(v,right(t),mid + 1,r);
        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    void push(int t) {
        if(hold.at(t)) {
            f.at(t) = ~f.at(t);
            hold.at(t) = 0;
            hold.at(left(t)) = !hold.at(left(t));
            hold.at(right(t)) = !hold.at(right(t));
        }
        return;
    }

    void add(int l,int r,int t = 1,int nl = -1,int nr = -1) {
        if( nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl >= l && nr <= r) return hold.at(t) = !hold.at(t),void();
        if(nl > r || nr < l) return;

        int mid = (nl + nr) >> 1;
        add(l,r,left(t),nl,mid);
        add(l,r,right(t),mid + 1,nr);
        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    box sum(int l,int r,int t = 1,int nl = -1,int nr = -1) {
        if( nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl >= l && nr <= r) return f.at(t) ^ hold.at(t);
        if(nl > r || nr < l) return box(-1);

        int mid = (nl + nr) >> 1;
        box ll = sum(l,r,left(t),nl,mid);
        box rr = sum(l,r,right(t),mid + 1,nr);
        
        if(ll.l == -1) return rr;
        if(rr.l == -1) return ll;
        return ll + rr;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<bool>f(a);
    for(int i = 0,tmp;i<a;i++) {
        cin>>tmp;
        f.at(i) = (tmp == 1);
    }

    seg_tree t(f);
    while(b--) {
        short tmp;cin>>tmp;
        if(tmp == 1) {
            int l,r;cin>>l>>r;
            t.add(l - 1,r - 1);
        }
        if(tmp == 2) {
            int l,r;cin>>l>>r;
            cout<<t.sum(l - 1,r - 1).now<<"\n";
        }
    }
    for(int i = 0;i<(a << 2);i++) {debug(t.f.at(i).now);}
    return 0;
}