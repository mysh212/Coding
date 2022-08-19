// Author : ysh
// 08/19/2022 Fri 22:29:12.05
// https://cses.fi/problemset/task/2166/
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int sum,pref;
    box(int a,int b):
        sum(a), pref(b) {};
    box(int n = 0):
        sum(n), pref(max(0LL,n)) {};
    box operator+(const box &a) const {
        return box(sum + a.sum,max(pref,sum + a.pref));
    }
};
struct seg_tree{
    vector<box>f,lt;
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
        for(auto i : f) {
            cout<<i.sum<<" ";
        }
        cout<<"\n";
    }

    void lcheck() {
        for(auto i : lt) {
            cout<<i.sum<<" ";
        }
        cout<<"\n";
    }

    void mt(int l,int r,vector<int>&v,int t = 0) {
        if(l == r) {
            f[t] = box(v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        mt(l,mid,v,left(t));
        mt(mid + 1,r,v,right(t));
        f[t] = f[left(t)] + f[right(t)];
        return;
    }

    box sum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
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

    // void push(int nl,int nr,int t) {
    //         f[t] += lt[t] * (nr - nl + 1);
    //         lt[right(t)] = lt[right(t)] + lt[t];
    //         lt[left(t)] = lt[left(t)] + lt[t];
    //         // radd(nl,mid,lt[t]);
    //         // radd(mid + 1,nr,lt[t]);
    //         lt[t] = 0;
    // }
    
    // int rsum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
    //     // cout<<nl<<" "<<nr<<"\n";
    //     if(nr == -1) nr = n - 1;
    //     if(nl == nr) return f[t] + lt[t];
    //     if(lt[t] != 0) push(nl,nr,t);
    //     // lcheck();
    //     // check();
    //     int mid = (nl + nr) >> 1;
    //     if(mid >= r) return rsum(l,r,left(t),nl,mid);
    //     if(mid < l) return rsum(l,r,right(t),mid + 1,nr);
    //     if(nl >= l && nr <= r) {
    //         return f[t];
    //     }
    //     return rsum(l,r,left(t),nl,mid) + rsum(l,r,right(t),mid + 1,nr);
    // }

    void add(int l,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) {
            f[t] = box(v);
            return;
        }
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid >= l) add(l,v,left(t),nl,mid);
        if(mid < l) add(l,v,right(t),mid + 1,nr);
        f[t] = f[left(t)] + f[right(t)];
        return;
    }

    // int radd(int l,int r,int v,int t = 0,int nl = 0,int nr = -1) {
    //     if(nl == nr) {
    //         f[t] += v;
    //         return v;
    //     }
    //     if(nr == -1) nr = n - 1;
    //     int mid = (nl + nr) >> 1;
    //     if(mid < l) {
    //         int tmp = radd(l,r,v,right(t),mid + 1,nr);
    //         f[t] += tmp;
    //         return tmp;
    //     }
    //     if(mid >= r) {
    //         int tmp = radd(l,r,v,left(t),nl,mid);
    //         f[t] += tmp;
    //         return tmp;
    //     }
    //     if(nl >= l && nr <= r) {
    //         lt[t] += v;
    //         return (nr - nl + 1) * v;
    //     }
    //     int rr = radd(l,r,v,right(t),mid + 1,nr);
    //     int ll = radd(l,r,v,left(t),nl,mid);
    //     f[t] += rr + ll;
    //     return rr + ll;
    // }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        // if(i != 0) r[i] = r[i - 1] + f[i];
        // else r[0] = f[0];
    }
    seg_tree t = seg_tree(f);
    while(b--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int aa,b;cin>>aa>>b;
            // int tmp = b;
            // b = b - f[aa - 1];
            f[aa - 1] = b;
            t.add(aa - 1,b);
            // t.check();
            // t.lcheck();
        }
        if(tmp == 2) {
            int a,b;cin>>a>>b;
            int ans = 0;
            if(a >= 2) ans = t.sum(a - 1,b - 1).pref;
            else ans = t.sum(a - 1,b - 1).pref;
            if(ans < 0) cout<<0<<"\n";
            else cout<<ans<<"\n";
        }
    }
    return 0;
}