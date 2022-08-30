// Author : ysh
// 08/25/2022 Thu 12:19:50.27
#include<bits/stdc++.h>
using namespace std;
struct seg_tree{
    vector<int>f;
    int n;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
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

    int mt(int l,int r,vector<int>&v,int t = 0) {
        if(l == r) {
            return f[t] = v[l];
        }
        int mid = (l + r) >> 1;
        return f[t] = mt(l,mid,v,left(t)) ^ mt(mid + 1,r,v,right(t));
    }

    int sum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        // cerr<<nl<<" "<<nr<<"\n";
        if(nl == nr) return f[t];
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid >= r) return sum(l,r,left(t),nl,mid);
        if(mid < l) return sum(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return f[t];
        }
        return sum(l,r,left(t),nl,mid) ^ sum(l,r,right(t),mid + 1,nr);
    }

    void add(int l,int o,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) {
            f[t] = v;
            return;
        }
        if(nr == -1) nr = n - 1;
        f[t] = f[t] ^ o ^ v;
        int mid = (nl + nr) >> 1;
        if(mid >= l) add(l,o,v,left(t),nl,mid);
        if(mid < l) add(l,o,v,right(t),mid + 1,nr);
        return;
    }
};
struct tree{
    vector<int>f;
    int n;

    tree(int n) {
        f.resize(n);
        this->n = n;
    }

    tree(vector<int>&f) {
        this->f.resize(f.size());
        this->n = f.size();
        int r = 0;
        for(int i : f) {
            add(r++,0,i);
        }
    }

    void add(int n,int o,int r) {
        for(;n < this->n;n = (n | (n + 1))) {
            f[n] = f[n] ^ o ^ r;
        }
    }

    int sum(int n) {
        int ans = 0;
        for(;n >= 0;n = (n & (n + 1)) - 1) {
            ans = ans ^ f[n];
        }
        return ans;
    }

    int sum(int l,int r) {
        if(l > r) swap(l,r);
        return sum(r) ^ sum(l - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree t = seg_tree(f);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        if(a == 0) cout<<t.sum(b - 1,c - 1)<<"\n";
        if(a == 1) {
            // int tmp = c - f[b - 1];
            t.add(b - 1,f[b - 1],c);
            f[b - 1] = c;
        }
    }
    return 0;
}