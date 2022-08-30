// Author : ysh
// 08/20/2022 Sat 11:00:25.59
// https://cses.fi/problemset/task/1735/
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
    vector<int>f,lt,st;
    vector<bool>ste;
    int n;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        lt.resize(n << 2);
        st.resize(n << 2);
        ste.resize(n << 2);
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
            cerr<<i<<" ";
        }
        cerr<<"\n";
    }

    void lcheck() {
        for(int i : lt) {
            cerr<<i<<" ";
        }
        cerr<<"\n";
    }

    void scheck() {
        for(int i : st) {
            cerr<<i<<" ";
        }
        cerr<<"\n";
    }

    void secheck() {
        for(int i : ste) {
            cerr<<i<<" ";
        }
        cerr<<"\n";
    }

    int mt(int l,int r,vector<int>&v,int t = 0) {
        if(l == r) {
            return f[t] = v[l];
        }
        int mid = (l + r) >> 1;
        return f[t] = mt(l,mid,v,left(t)) + mt(mid + 1,r,v,right(t));
    }

    int sum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // //debug(nl,nr);
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

    // void tf(int nl,int nr,int t) {
    //     if(ste[t]) {
    //         f[t] = st[t] * (nr - nl + 1);
    //         st[t] = 0;
    //         ste[t] = 0;
    //         lt[t] = 0;
    //     }
    //     f[t] += lt[t];
    //     lt[t] = 0;
    //     return;
    // }

    void push(int nl,int nr,int t) {
        // update(nl,nr,t);
            if(nl == nr) {
                cst(nl,nr,t);
                return;
            }
            // tf(((nl + nr) >> 1) + 1,nr,right(t));
            // tf(nl,((nl + nr) >> 1),left(t));
            if(ste[t]) {
                // cerr<<"st: "<<st[t]<<"\n";
                f[t] = st[t] * (nr - nl + 1);
                lt[t] = 0;
                ste[right(t)] = ste[left(t)] = 1;
                st[right(t)] = st[left(t)] = st[t];
                st[t] = 0;
                ste[t] = 0;
                // debug(f[t],lt[t],st[t],(int) ste[t]);
                return;
            }
            f[t] += lt[t] * (nr - nl + 1);
            lt[right(t)] = lt[right(t)] + lt[t];
            lt[left(t)] = lt[left(t)] + lt[t];
            // radd(nl,mid,lt[t]);
            // radd(mid + 1,nr,lt[t]);
            lt[t] = 0;
            // debug(f[t],lt[t],st[t],(int) ste[t]);
    }
    
    int rsum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        //debug(nl,nr,f[t],st[t],(int) ste[t],lt[t]);
        // cout<<nl<<" "<<nr<<"\n";
        if(nr == -1) nr = n - 1;
        push(nl,nr,t);
        if(nl == nr) return (st[t] != 0 ? st[t] : f[t] + lt[t]);
        // lcheck();
        // check();
        int mid = (nl + nr) >> 1;
        if(mid >= r) return rsum(l,r,left(t),nl,mid);
        if(mid < l) return rsum(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return f[t];
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

    void update(int nl,int nr,int t) {
        if(nl == nr) return;
        push(nl,nr,t);
        push(((nl + nr) >> 1) + 1,nr,right(t));
        push(nl,((nl + nr) >> 1),left(t));
        f[t] = f[right(t)] + f[left(t)];
        debug(f[t],lt[t],st[t],(int) ste[t]);
        debug(f[right(t)],lt[right(t)],st[right(t)],(int) ste[right(t)]);
        debug(f[left(t)],lt[left(t)],st[left(t)],(int) ste[left(t)]);
        return;
    }

    void radd(int l,int r,int v,int t = 0,int nl = 0,int nr = -1) {
        //debug(nl,nr,f[t],st[t],(int) ste[t],lt[t]);
        if(nr == -1) nr = n - 1;
        if(nl == nr) {
            f[t] += v;
            return;
        }
        push(nl,nr,t);
        int mid = (nl + nr) >> 1;
        update(nl,nr,t);
        if(mid < l) {
            radd(l,r,v,right(t),mid + 1,nr);
            update(nl,nr,t);
            return;
        }
        if(mid >= r) {
            radd(l,r,v,left(t),nl,mid);
            update(nl,nr,t);
            return;
        }
        if(nl >= l && nr <= r) {
            update(nl,nr,t);
            lt[t] += v;
            push(nl,nr,t);
            return;
        }
        radd(l,r,v,right(t),mid + 1,nr);
        radd(l,r,v,left(t),nl,mid);
        update(nl,nr,t);
        return;
    }

    void cst(int nl,int nr,int t) {
        if(nl != nr) {
            push(nl,nr,t);
            return;
        }
        if(ste[t]) {
            f[t] = st[t];
            lt[t] = 0;
            st[t] = 0;
            ste[t] = 0;
        }
        f[t] = f[t] + lt[t];
        lt[t] = 0;
        // debug(f[t],lt[t],st[t],(int) ste[t]);
        return;
    }

    void rset(int l,int r,int v,int t = 0,int nl = 0,int nr = -1) {
        //debug(nl,nr,f[t],st[t],(int) ste[t],lt[t]);
        if(nr == -1) nr = n - 1;
        push(nl,nr,t);
        if(nl == nr) {
            f[t] = v;
            return;
        }
        int mid = (nl + nr) >> 1;
        if(mid < l) {
            rset(l,r,v,right(t),mid + 1,nr);
            update(nl,nr,t);
            return;
        }
        if(mid >= r) {
            rset(l,r,v,left(t),nl,mid);
            update(nl,nr,t);
            return;
        }
        if(nl >= l && nr <= r) {
            st[t] = v;
            ste[t] = 1;
            //debug(v);
            // printf("not pushed: nl: %d nr : %d st[t]: %d f[t]: %d st[right(t)]: %d st[left(t)]: %d\n",nl,nr,st[t],f[t],st[right(t)],st[left(t)]);
            push(nl,nr,t);
            // printf("pushed: nl: %d nr : %d st[t]: %d f[t]: %d st[right(t)]: %d st[left(t)]: %d\n",nl,nr,st[t],f[t],st[right(t)],st[left(t)]);
            return;
        }
        rset(l,r,v,right(t),mid + 1,nr);
        rset(l,r,v,left(t),nl,mid);
        update(nl,nr,t);
        return;
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
        int a,b,c;cin>>a>>b>>c;
            // t.check();
            // t.lcheck();
            // t.scheck();
            // t.secheck();
        if(a == 1) {
            int d;cin>>d;
            t.radd(b - 1,c - 1,d);
        }
        if(a == 2) {
            int d;cin>>d;
            t.rset(b - 1,c - 1,d);
        }
        if(a == 3) {
            cout<<t.rsum(b - 1,c - 1)<<"\n";
        }
    }
    return 0;
}