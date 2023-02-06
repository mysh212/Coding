// Author : ysh
// 02/06/2023 Mon 16:50:56.61
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seg_tree{
    int n;
    vector<long long>f,lz;

    seg_tree(vector<int>&f) {
        n = f.size();
        this->f.resize(n << 2);
        lz.resize(n << 2);
        mt(f);
    }

    long long exact(int t,int l,int r) {
        if(l == r) return f.at(t) + lz.at(t);
        return f.at(t) + lz.at(t) * (r - l + 1);
    }

    void pull(int t,int l,int r) {
        push(t,l,r);
        if(l == r) return;
        int mid = (l + r) >> 1;
        f.at(t) = exact((t << 1) + 1,l,mid) + exact((t << 1) + 2,mid + 1,r);
        return;
    }

    void push(int t,int l,int r) {
        if(l == r) return;
        if(lz.at(t) == 0) return;
        lz.at((t << 1) + 1) += lz.at(t);
        lz.at((t << 1) + 2) += lz.at(t);
        f.at(t) = f.at(t) + lz.at(t) * (r - l + 1);
        lz.at(t) = 0;
        return;
    }

    void mt(vector<int>&f,int t = 0,int l = -1,int r = -1) {
        if(l == -1 && r == -1) l = 0,r = n - 1;
        if(l == r) return this->f.at(t) = f.at(l),void();
        int mid = (l + r) >> 1;
        mt(f,(t << 1) + 1,l,mid);
        mt(f,(t << 1) + 2,mid + 1,r);
        pull(t,l,r);
        return;
    }

    void add(int l,int r,int v,int t = 0,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        push(t,nl,nr);
        if(nl > r || nr < l) return;
        if(nl == nr) return f.at(t) += v,void();
        if(nl >= l && nr <= r) return lz.at(t) += v,void();

        int mid = (nl + nr) >> 1;
        add(l,r,v,(t << 1) + 1,nl,mid);
        add(l,r,v,(t << 1) + 2,mid + 1,nr);
        pull(t,nl,nr);
        return;
    }

    long long sum(int l,int r,int t = 0,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        push(t,nl,nr);
        int mid = (nl + nr) >> 1;
        if(nl > r || nr < l) return 0;
        if(nl >= l && nr <= r) return exact(t,nl,nr);
        return sum(l,r,(t << 1) + 1,nl,mid) + sum(l,r,(t << 1) + 2,mid + 1,nr);
    }

    void debug() {
        return;
        for(int i : f) cout<<i<<" ";
        cout<<"\n";
        for(int i : lz) cout<<i<<" ";
        cout<<"\n";
        for(int i = 0;i<n;i++) cout<<sum(i,i)<<" ";
        cout<<"\n";
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    seg_tree t(f);

    int m;cin>>m;
    while(m--) {
        t.debug();
        // cout<<"\n";
        int a;cin>>a;
        if(a == 2) {
            int a,b;cin>>a>>b;
            a--;b--;
            cout<<t.sum(a,b)<<"\n";
        }
        if(a == 1) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            t.add(a,b,c);
        }
    }
    return 0;
}