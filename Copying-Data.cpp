// Author : ysh
// 06/06/2023 Tue 10:37:34.93
// https://codeforces.com/contest/292/problem/E
#include<bits/stdc++.h>

using namespace std;
using namespace std;

template<typename T>
struct seg_tree{
    int n;
    vector<T>f,hold;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        hold.resize(n << 2);
    }

    seg_tree(vector<T>&v) {
        this->n = v.size();
        f.resize(n << 2);
        hold.resize(n << 2);
        mt(1,0,n - 1,v);
    }
    
    void push(int t,int l,int r) {
        if(hold.at(t) == 0) return;
        f.at(t) = hold.at(t) * (r - l + 1);
        hold.at(t << 1) = hold.at(t);
        hold.at((t << 1) | 1) = hold.at(t);
        hold.at(t) = hold.at(t) - hold.at(t);
    }

    T exact(int t,int l,int r) {
        if(hold.at(t) == 0) return f.at(t);
        return hold.at(t) * (r - l + 1);
    }

    T re(int t,int l,int r) {
        return f.at(t) = (exact((t << 1),l,(l + r) >> 1) + exact((t << 1) | 1,((l + r) >> 1) + 1,r));
    }

    T mt(int t,int l,int r,vector<T>&v) {
        if(l == r) return f.at(t) = v.at(l);
        int mid = (l + r) >> 1;
        return f.at(t) = mt((t << 1),l,mid,v) + mt((t << 1) | 1,mid + 1,r,v);
    }

    void add(int nl,int nr,T v,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return;
        if(l == r) {
            f.at(t) = v;
            hold.at(t) = 0;
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) = v;
            return;
        }
        add(nl,nr,v,t << 1,l,mid),add(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }

    void add(int l,int v) {
        add(l,l,v);
        return;
    }

    T sum(int nl,int nr,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return 0;
        if(l == r) return exact(t,l,r);
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) return exact(t,l,r);
        return sum(nl,nr,t << 1,l,mid) + sum(nl,nr,(t << 1) | 1,mid + 1,r);
    }

    void debug() {
        for(int i = 0;i<n;i++) {
            cerr<<sum(i,i)<<" ";
        }
        cerr<<"<- original debug\n";
        int last = 0;
        for(int i = 0;i<n;i++) {
            cerr<<(last += sum(i,i))<<" ";
        }
        cerr<<"<- tree debug\n";
        cerr<<"Overall sum: "<<sum(0,n - 1)<<"\n";
        return;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(a);
    for(int &i : f) cin>>i;
    for(int &i : g) cin>>i;

    vector<int>pre(a,1);
    pre.at(0) = a;

    seg_tree<int>t(pre);
    while(b--) {
        int r;cin>>r;
        if(r == 1) {
            int x,y,z;cin>>x>>y>>z;
            z = min(z,a - y + 1);
            x--;y--;
            int bkp = -1;
            if(y + z != a) bkp = t.sum(0,y + z);
            t.add(y,y,x - (y == 0 ? 0 : t.sum(0,y - 1)));
            t.add(y + 1,y + z - 1,1);
            // cerr<<"bkp: "<<bkp<<"\n";
            // if(y + z != a) cerr<<"pre: "<<t.sum(0,y + z - 1)<<"\n";
            if(y + z != a) t.add(y + z,y + z,bkp - t.sum(0,y + z - 1));
            // printf("(%d,%d,%d)",y + z,y + z,bkp - t.sum(0,y + z - 1));
            // t.debug();
        }
        if(r == 2) {
            int x;cin>>x;
            x--;
            int ans = t.sum(0,x);
            if(ans < a) cout<<f.at(ans)<<"\n";
            else cout<<g.at(ans - a)<<"\n";
        }
    }
    return 0;
}