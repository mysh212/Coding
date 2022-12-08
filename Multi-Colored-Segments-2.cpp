// Author : ysh
// 12/03/2022 Sat 20:52:06.38
// https://codeforces.com/contest/1741/problem/F
#include<bits/stdc++.h>
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
        f.at(t) += f.at(t) || hold.at(t);
        hold.at(t << 1) = hold.at(t << 1) || hold.at(t);
        hold.at((t << 1) | 1) = hold.at((t << 1) | 1) || hold.at(t);
        hold.at(t) = 0;
    }

    T exact(int t,int l,int r) {
        return f.at(t) || hold.at(t);
    }

    T re(int t,int l,int r) {
        return f.at(t) = (exact((t << 1),l,(l + r) >> 1) || exact((t << 1) | 1,((l + r) >> 1) + 1,r));
    }

    T mt(int t,int l,int r,vector<T>&v) {
        if(l == r) return f.at(t) = v.at(l);
        int mid = (l + r) >> 1;
        return f.at(t) = mt((t << 1),l,mid,v) || mt((t << 1) | 1,mid + 1,r,v);
    }

    void add(int nl,int nr,T v,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return;
        if(l == r) {
            f.at(t) = 1;
            return;
        }
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) {
            hold.at(t) = 1;
            return;
        }
        add(nl,nr,v,t << 1,l,mid),add(nl,nr,v,(t << 1) | 1,mid + 1,r);
        re(t,l,r);
        return;
    }

    T sum(int nl,int nr,int t = 1,int l = 0,int r = -1) {
        if(r == -1) r = n - 1;
        if(nr < l || nl > r) return 0;
        if(l == r) return f.at(t) || hold.at(t);
        push(t,l,r);
        int mid = (l + r) >> 1;
        if(nl <= l && nr >= r) return exact(t,l,r);
        return sum(nl,nr,t << 1,l,mid) || sum(nl,nr,(t << 1) | 1,mid + 1,r);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<pair<int,int>>>f(n);
        vector<pair<int,int>>v(n);
        for(int i = 0;i<n;i++) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;c--;
            if(a > b) swap(a,b);
            f.at(c).push_back({b,c});
            v.at(i) = {a,b};
        }
        map<pair<int,int>>m;
        set<int>left,right;
        for(auto &i : f) {
            for(pair<int,int> &j : i) {
                int ll = INT_MAX;
                int rr = INT_MAX;

            }
            for(int &j : i) {
                
            }
        }
    }
}