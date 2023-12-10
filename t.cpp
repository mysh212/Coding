// Author : ysh
// 2023/12/10 Sun 19:53:20
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    #define left(i) (i << 1)
    #define right(i) ((i << 1) | 1)
    vector<int>f;
    int n;

    box(int n):
        f(n << 2), n(n) {};

    box(vector<int>&v):
        box(v.size()) {
            mt(0,n - 1,v);
        }
    
    void mt(int l,int r,vector<int>&v,int t = 1) {
        if(l == r) return f.at(t) = v.at(l),void();
        int mid = (l + r) >> 1;
        mt(l,mid,v,left(t));
        mt(mid + 1,r,v,right(t));
        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    void add(int l,int v,int t = 1,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl == nr) return f.at(t) += v,void();
        int mid = (nl + nr) >> 1;
        if(l > mid) add(l,v,right(t),mid + 1,nr);
        else add(l,v,left(t),nl,mid);

        f.at(t) = f.at(left(t)) + f.at(right(t));
        return;
    }

    int sum(int l,int r,int t = 1,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl >= l && nr <= r) return f.at(t);
        if(nr < l || nl > r) return 0;

        int mid = (nl + nr) >> 1;
        return sum(l,r,left(t),nl,mid) + sum(l,r,right(t),mid + 1,nr);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;

    box t(f);
    while(b--) {
        short a;cin>>a;
        if(a == 1) {
            int a,b;cin>>a>>b;
            a--;
            b = b - f.at(a);
            t.add(a,b);
            f.at(a) += b;
        }
        if(a == 2) {
            int a,b;cin>>a>>b;
            a--;b--;
            cout<<t.sum(a,b)<<"\n";
        }
    }
    return 0;
}