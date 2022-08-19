// Author : ysh
// 08/19/2022 Fri 20:31:50.68
#include<bits/stdc++.h>
using namespace std;
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

    void push(int nl,int nr,int t) {
            f[t] += lt[t] * (nr - nl + 1);
            lt[right(t)] = lt[right(t)] + lt[t];
            lt[left(t)] = lt[left(t)] + lt[t];
            // radd(nl,mid,lt[t]);
            // radd(mid + 1,nr,lt[t]);
            lt[t] = 0;
    }
    
    int rsum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // cout<<nl<<" "<<nr<<"\n";
        if(nr == -1) nr = n - 1;
        if(nl == nr) return f[t] + lt[t];
        if(lt[t] != 0) push(nl,nr,t);
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
        int rr = radd(l,r,v,right(t),mid + 1,nr);
        int ll = radd(l,r,v,left(t),nl,mid);
        f[t] += rr + ll;
        return rr + ll;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree t = seg_tree(f);
    int m;cin>>m;
    // t.check();
    while(m--) {
        int a;cin>>a;
        if(a == 1) {
            int a,b,c;cin>>a>>b>>c;
            t.radd(a - 1,b - 1,c);
            // t.check();
            // t.lcheck();
        }
        if(a == 2) {
            int a,b;cin>>a>>b;
            cout<<t.rsum(a - 1,b - 1)<<"\n";
        }
    }
    return 0;
}