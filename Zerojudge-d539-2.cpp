// Author : ysh
// 08/18/2022 Thu 16:01:07.31
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
        return f[t] = max(mt(l,mid,v,left(t)),mt(mid + 1,r,v,right(t)));
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
        return max(sum(l,r,left(t),nl,mid),sum(l,r,right(t),mid + 1,nr));
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
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree t = seg_tree(f);
    // t.check();
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        if(a > b) swap(a,b);
        cout<<t.sum(a - 1,b - 1)<<"\n";
    }
    return 0;
}