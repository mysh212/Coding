// Author : ysh
// 2023/10/12 Thu 00:56:57
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#define int int64_t // long long
struct seg_tree{
    #define left(t) (t << 1)
    #define right(t) ((t << 1) | 1)

    vector<int>f;
    int n;

    seg_tree(int n = 0):
        n(n), f(n << 2) {};

    seg_tree(vector<int>&v) {
        this->n = v.size();
        f.resize(n << 2);
        mt(v);
    }

    void mt(vector<int>&v,int t = 1,int l = -1,int r = -1) {
        if(l == -1 && r == -1) l = 0,r = n - 1;
        if(l == r) return f.at(t) = v.at(l),void();
        int mid = (l + r) >> 1;
        mt(v,left(t),l,mid);
        mt(v,right(t),mid + 1,r);
        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    void add(int x,int v,int t = 1,int l = -1,int r = -1) {
        if(l == -1 && r == -1) l = 0,r = n - 1;
        if(l == r) return f.at(t) += v,void();
        int mid = (l + r) >> 1;
        if(x <= mid) add(x,v,left(t),l,mid);
        else add(x,v,right(t),mid + 1,r);
        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    int get(int ll,int rr,int t = 1,int l = -1,int r = -1) {
        if(l == -1 && r == -1) l = 0,r = n - 1;
        if(l > rr || r < ll) return 0;
        if(l >= ll && r <= rr) return f.at(t);
        int mid = (l + r) >> 1;
        return get(ll,rr,left(t),l,mid) + get(ll,rr,right(t),mid + 1,r);
    }

    void debug() {
        return;
        for(int i = 0,len = 20;i<len;i++) {
            cerr<<f.at(i)<<" ";
        }
        cerr<<"\n";
        for(int i = 0;i<20;i++) {
            cerr<<get(i,i)<<" ";
        }
        cerr<<"\n";
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

    seg_tree t(int(1e6) + 2);
    long long ans = 0;
    for(int &i : f) {
        // cerr<<ans<<"\n";
        // t.debug();
        ans = ans + t.get(i + 1,int(1e6) + 1);
        t.add(i,1);
    }

    cout<<ans;
    return 0;
}