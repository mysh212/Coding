// Author : ysh
// 08/18/2022 Thu 20:49:48.16
// https://cses.fi/problemset/hack/1651/list/
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

struct seg_tree{
    vector<int>f,lt;
    int n;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        lt.resize(n << 2);
        // mt(0,n - 1);
    }

    seg_tree(vector<int>&v):
    seg_tree(v.size()) {
        // this->n = v.size();
        // f.resize(n << 2);
        mt(0,n - 1,v);
    }

    inline int left(int n) {
        return (n << 1) + 1;
    }
    inline int right(int n) {
        return (n << 1) + 2;
    }

    void mt(int l,int r,int t = 0) {
        // cout<<l<<" "<<r<<"\n";
        // if(l == 2 && r == 1) return;
        // system("sleep 10");
        if(l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        mt(l,mid,left(t));
        mt(mid + 1,r,right(t));
    }

    void check() {
        for(int i : f) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    void lcheck() {
        for(int i : lt) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }

    int mt(int l,int r,vector<int>&v,int t = 0) {
        if(l == r) {
            return f[t] = v[l];
        }
        int mid = (l + r) >> 1;
        return f[t] = mt(l,mid,v,left(t)) + mt(mid + 1,r,v,right(t));
    }

    int sum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // debug(nl,nr);
        if(nl == nr) return f[t];
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid >= r) return sum(l,r,left(t),nl,mid);
        if(mid < l) return sum(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return f[t];
        }
        return sum(l,r,left(t),nl,mid) + sum(l,r,right(t),mid + 1,nr);
    }

    int rsum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // debug(nl,nr);
        if(nl == nr) return f[t] + lt[t];
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(nl >= l && nr <= r) {
            return f[t] + (lt[t] * (nr - nl + 1));
        }
        if(lt[t] != 0) {
            radd(nl,mid,lt[t]);
            radd(mid + 1,nr,lt[t]);
            lt[t] = 0;
        }
        if(mid >= r) {
            return rsum(l,r,left(t),nl,mid);
        }
        if(mid < l) {
            return rsum(l,r,right(t),mid + 1,nr);
        }
        return rsum(l,r,left(t),nl,mid) + rsum(l,r,right(t),mid + 1,nr);
    }

    void add(int l,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) {
            f[t] += v;
            return;
        }
        if(nr == -1) nr = n - 1;
        f[t] += v;
        int mid = (nl + nr) >> 1;
        if(mid >= l) add(l,v,left(t),nl,mid);
        if(mid < l) add(l,v,right(t),mid + 1,nr);
        return;
    }

    int radd(int l,int r,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) {
            f[t] += v;
            return v;
        }
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid < l) {
            int tmp = radd(l,r,v,right(t),mid + 1,nr);
            f[t] += tmp;
            return tmp;
        }
        if(mid >= r) {
            int tmp = radd(l,r,v,left(t),nl,mid);
            f[t] += tmp;
            return tmp;
        }
        if(nl >= l && nr <= r) {
            lt[t] += v;
            return (nr - nl + 1) * v;
        }
        // f[t] += v;
        // if(mid >= l) radd(l,r,v,left(t),nl,mid);
        // if(mid < l) radd(l,r,v,right(t),mid + 1,nr);
        int rr = radd(l,r,v,right(t),mid + 1,nr);
        int ll = radd(l,r,v,left(t),nl,mid);
        f[t] += rr + ll;
        return rr + ll;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    seg_tree t = seg_tree(f);
    while(b--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int a,b,c;cin>>a>>b>>c;
            t.radd(a - 1,b - 1,c);
            // t.lcheck();
            // t.check();
        }
        if(tmp == 2) {
            int a;cin>>a;
            cout<<t.rsum(a - 1,a - 1)<<"\n";
        }
    }
    return 0;
}
