// Author : ysh
// 08/19/2022 Fri 21:39:25.22
// https://cses.fi/problemset/task/2166
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seg_tree{
    vector<int>f,lt,s;
    int n;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        lt.resize(n << 2);
        s.resize(n << 2);
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
            return f[t] = s[t] = v[l];
        }
        int mid = (l + r) >> 1;
        f[t] = max(mt(l,mid,v,left(t)),mt(mid + 1,r,v,right(t)));
        s[t] = s[right(t)] + s[left(t)];
        return f[t];
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
            f[t] += lt[t];
            s[t] += lt[t] * (nr - nl + 1);
            lt[right(t)] = lt[right(t)] + lt[t];
            lt[left(t)] = lt[left(t)] + lt[t];
            // radd(nl,mid,lt[t]);
            // radd(mid + 1,nr,lt[t]);
            lt[t] = 0;
    }
    
    int rmax(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // cout<<nl<<" "<<nr<<"\n";
        if(nr == -1) nr = n - 1;
        if(nl == nr) return f[t] + lt[t];
        if(lt[t] != 0) push(nl,nr,t);
        // lcheck();
        // check();
        int mid = (nl + nr) >> 1;
        if(mid >= r) return rmax(l,r,left(t),nl,mid);
        if(mid < l) return rmax(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return f[t];
        }
        return max(rmax(l,r,left(t),nl,mid),rmax(l,r,right(t),mid + 1,nr));
    }

    int rsum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // cout<<nl<<" "<<nr<<"\n";
        if(nr == -1) nr = n - 1;
        if(nl == nr) return s[t] + lt[t];
        if(lt[t] != 0) push(nl,nr,t);
        // lcheck();
        // check();
        int mid = (nl + nr) >> 1;
        if(mid >= r) return rsum(l,r,left(t),nl,mid);
        if(mid < l) return rsum(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return s[t];
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

    void radd(int l,int r,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) {
            f[t] += v;
            s[t] += v;
            return;
        }
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid < l) {
            radd(l,r,v,right(t),mid + 1,nr);
            f[t] = max(f[right(t)] + lt[right(t)],f[left(t)] + lt[left(t)]);
            s[t] = s[right(t)] + s[left(t)];
            return;
        }
        if(mid >= r) {
            radd(l,r,v,left(t),nl,mid);
            f[t] = max(f[right(t)] + lt[right(t)],f[left(t)] + lt[left(t)]);
            s[t] = s[right(t)] + s[left(t)];
            return;
        }
        if(nl >= l && nr <= r) {
            lt[t] += v;
            push(nl,nr,t);
            return;
        }
        radd(l,r,v,right(t),mid + 1,nr);
        radd(l,r,v,left(t),nl,mid);
        f[t] = max(f[right(t)] + lt[right(t)],f[left(t)] + lt[left(t)]);
        s[t] = s[right(t)] + s[left(t)];
        return;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),r(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        if(i != 0) r[i] = r[i - 1] + f[i];
        else r[0] = f[0];
    }
    seg_tree t = seg_tree(r);
    while(b--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int aa,b;cin>>aa>>b;
            int tmp = b;
            b = b - f[aa - 1];
            f[aa - 1] = tmp;
            t.radd(aa - 1,a - 1,b);
            // t.check();
            // t.lcheck();
        }
        if(tmp == 2) {
            int a,b;cin>>a>>b;
            int ans = 0;
            if(a >= 2) ans = t.rmax(a - 1,b - 1) - t.rsum(a - 2,a - 2);
            else ans = t.rmax(a - 1,b - 1);
            if(ans < 0) cout<<0<<"\n";
            else cout<<ans<<"\n";
        }
    }
    return 0;
}