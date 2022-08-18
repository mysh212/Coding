// Author : ysh
// 08/18/2022 Thu  9:03:02
// https://cses.fi/problemset/task/2166
#include<bits/stdc++.h>
using namespace std;
class seg_tree{
    public:
    vector<int>f;
    int n;

    seg_tree(int n) {
        this->n = n;
        f.resize(n << 2);
        mt(0,n - 1);
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

    int mt(int l,int r,vector<int>&v,int t = 0) {
        if(l == r) {
            f[t] = v[l];
            return 0;
        }
        int mid = (l + r) >> 1;
        f[t] = mt(l,mid,v,left(t)) + mt(mid + 1,r,v,right(t));
    }

    int sum(int l,int r,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) return f[l];
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid >= r) return sum(l,r,left(t),nl,mid);
        if(mid < l) return sum(l,r,right(t),mid + 1,nr);
        if(nl >= l && nr <= r) {
            return f[t];
        }
        return sum(l,r,left(t),nl,mid) + sum(l,r,right(t),mid + 1,nr);
    }

    void add(int l,int v,int t = 0,int nl = 0,int nr = -1) {
        if(nl == nr) return;
        if(nr == -1) nr = n - 1;
        int mid = (nl + nr) >> 1;
        if(mid >= l) add(l,v,left(t),nl,mid);
        if(mid < l) add(l,v,right(t),mid + 1,nr);
        return;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f({1,0,1,0,1,0,1,0});
    seg_tree t = seg_tree(8);
    int a,b;
    t.add(1,2);
    while(cin>>a>>b) {
        cout<<t.sum(a,b);
    }
    return 0;
}
