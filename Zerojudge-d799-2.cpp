// Author : ysh
// 11/22/2022 Tue 22:15:44.21
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
struct seg_tree{
    int n;
    vector<int>f,hold;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        hold.resize(n << 2);
    }

    seg_tree(vector<int>&v) {
        this->n = v.size();
        f.resize(n << 2);
        hold.resize(n << 2);
        mt(1,0,n - 1,v);
    }
    
    void push(int t,int l,int r) {
        f.at(t) += hold.at(t) * (r - l + 1);
        hold.at(t << 1) += hold.at(t);
        hold.at((t << 1) | 1) += hold.at(t);
        hold.at(t) = 0;
    }

    int exact(int t,int l,int r) {
        return f.at(t) + hold.at(t) * (r - l + 1);
    }

    int re(int t,int l,int r) {
        return f.at(t) = (exact((t << 1),l,(l + r) >> 1) + exact((t << 1) | 1,((l + r) >> 1) + 1,r));
    }

    int mt(int t,int l,int r,vector<int>&v) {
        if(l == r) return f.at(t) = v.at(l);
        int mid = (l + r) >> 1;
        return f.at(t) = mt((t << 1),l,mid,v) + mt((t << 1) | 1,mid + 1,r,v);
    }

    void add(int t,int l,int r,int nl,int nr,int v) {
        if(nr < l || nl > r) return;
        if(l == r) {
            f.at(t) += v;
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) += v;
            return;
        }
        add(t << 1,l,mid,nl,nr,v),add((t << 1) | 1,mid + 1,r,nl,nr,v);
        re(t,l,r);
        return;
    }

    long long sum(int t,int l,int r,int nl,int nr) {
        if(nr < l || nl > r) return 0;
        if(l == r) return f.at(t) + hold.at(t);
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) return exact(t,l,r);
        return sum(t << 1,l,mid,nl,nr) + sum((t << 1) | 1,mid + 1,r,nl,nr);
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
    seg_tree t(f);
    int m;cin>>m;
    while(m--) {
        int a;cin>>a;
        if(a == 1) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            t.add(1,0,n - 1,a,b,c);
        }
        if(a == 2) {
            int a,b;cin>>a>>b;
            a--;b--;
            cout<<t.sum(1,0,n - 1,a,b)<<"\n";
        }
    }
    return 0;
}