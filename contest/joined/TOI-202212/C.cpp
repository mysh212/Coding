// Author : ysh
// 12/29/2022 Thu 21:25:07.10
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
struct box{
    int n;
    deque<int>f;
    box() {
        n = 0;
        f.resize(20);
    }
    box(int n) {
        this->n = n;
        int r = n;
        f.resize(20);
        f.at(0) = n;
        for(int i = 1;i<=19;i++) {
            f.at(i) = r = r / 10;
        }
        // debug(n,f);
    }
    box operator+(box a) {
        return box(n + a.n);
    }
    box operator+(int r) {
        box tmp = *this;
        tmp.n = f.at(r);
        while(r--) {
            tmp.f.pop_front();
            tmp.f.push_back(0);
        }
        return tmp;
    }
    box operator+=(box a) {
        *this = a;
        return *this;
    }
    box operator+=(int r) {
        // box tmp;
        n = f.at(r);
        while(r--) {
            f.pop_front();
            f.push_back(0);
        }
        return *this;
    }
};
// template<typename box>
struct seg_tree{
    int n;
    vector<box>f;
    vector<int>hold;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        hold.resize(n << 2);
    }

    seg_tree(vector<box>&v) {
        this->n = v.size();
        f.resize(n << 2);
        hold.resize(n << 2);
        mt(1,0,n - 1,v);
    }
    
    void push(int t,int l,int r) {
        //debug(f.at(t).n,hold.at(t));
        f.at(t) += hold.at(t);
        hold.at(t << 1) += hold.at(t);
        hold.at((t << 1) | 1) += hold.at(t);
        hold.at(t) = 0;
        //debug(f.at(t).n);
        return;
    }

    box exact(int t,int l,int r) {
        return f.at(t) + hold.at(t);
    }

    box re(int t,int l,int r) {
        return f.at(t) = (exact((t << 1),l,(l + r) >> 1) + exact((t << 1) | 1,((l + r) >> 1) + 1,r));
    }

    box mt(int t,int l,int r,vector<box>&v) {
        //debug(l,r,t);
        if(l == r) return f.at(t) = v.at(l);
        int mid = (l + r) >> 1;
        return f.at(t) = mt((t << 1),l,mid,v) + mt((t << 1) | 1,mid + 1,r,v);
    }

    void add(int nl,int nr,int v,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
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
        add(nl,nr,v,t << 1,l,mid),add(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }

    void fix(int nl,int nr,int v,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return;
        if(l == r) {
            f.at(t) = box(v);
            hold.at(t) = 0;
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) += v;
            return;
        }
        fix(nl,nr,v,t << 1,l,mid),fix(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }

    box sum(int nl,int nr,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return box();
        if(l == r) return f.at(t) + hold.at(t);
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) return exact(t,l,r);
        return sum(nl,nr,t << 1,l,mid) + sum(nl,nr,(t << 1) | 1,mid + 1,r);
    }

    void print() {
        for(int i = 0;i<n;i++) {
            cerr<<sum(i,i).n<<" ";
        }
        cerr<<"\n";
        return;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(a);
    for(box &i : f) {
        int tmp;cin>>tmp;
        i = box(tmp);
    }
    seg_tree t(f);
    // t.print();
    while(b--) {
        int a,b,c;cin>>a>>b>>c;
        if(a == 1) cout<<t.sum(b - 1,c - 1).n<<"\n";
        if(a == 3) t.fix(b - 1,b - 1,c);
        if(a == 2) t.add(b - 1,c - 1,1);
        // t.print();
    }
    // t.print();
    return 0;
}