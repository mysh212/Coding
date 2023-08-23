// Author : ysh
// 2023/08/22 Tue 10:53:22
#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct seg_tree{
    int n;
    vector<T>f;
    vector<bool>hold;
 
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
        if(hold.at(t)) f.at(t) = (r - l + 1) - f.at(t);
        hold.at(t << 1) = hold.at(t) ^ hold.at(t << 1);
        hold.at((t << 1) | 1) = hold.at(t) ^ hold.at((t << 1) | 1);
        hold.at(t) = 0;
    }
 
    T exact(int t,int l,int r) {
        return (hold.at(t) ? (r - l + 1) - f.at(t) : f.at(t));
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
            f.at(t) = !f.at(t);
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) = !hold.at(t);
            return;
        }
        add(nl,nr,v,t << 1,l,mid),add(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }
 
    void add(int l,T v) {
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
        cerr<<"tree debug -> ";
        for(int i = 0;i<n;i++) {
            cerr<<sum(i,i)<<" ";
        }
        cerr<<"\n";
    }
 
    void ddebug() {
        cerr<<"tree debug -> ";
        for(int i = 0;i<(n << 2);i++) {
            cerr<<f.at(i)<<" ";
        }
        cerr<<"\n";
        cerr<<"tree hold debug -> ";
        for(int i = 0;i<(n << 2);i++) {
            cerr<<hold.at(i)<<" ";
        }
        cerr<<"\n";
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    a = a + 2;
    int m = sqrt(a) + 1;
    vector<seg_tree<int>>f(m,seg_tree<int>(a));
    vector<bool>mark(a);
    while(b--) {
        short tmp;cin>>tmp;
        if(tmp == 1) {
            int a,b;cin>>a>>b;
            int c;cin>>c;
            if(c >= m) {
                if(c >= a && c <= b) mark.at(c) = !mark.at(c);
            } else {
                f.at(c).add(a,b,1);
            }
        }
        if(tmp == 2) {
            int c;cin>>c;
            bool now = mark.at(c);
            for(int i = 1;i<m;i++) {
                if(c % i == 0) {
                    now ^= f.at(i).sum(c,c);
                }
            }
            cout<<(now ? "Yes" : "No")<<"\n";
        }
    }
    for(int c = 1;c<=a - 2;c++) {
            bool now = mark.at(c);
            for(int i = 1;i<m;i++) {
                if(c % i == 0) {
                    now ^= f.at(i).sum(c,c);
                }
            }
            cout<<(now ? "Yes" : "No")<<" ";
    }
    return 0;
}