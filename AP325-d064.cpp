// Author : ysh
// 07/18/2022 Mon  9:39:51.29
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int) 2e6 + 5;
struct tree{
    tree* l;
    tree* r;
    int left,right;
    int v = 0;
    int i;
    bool o = 0;
};
vector<tree>f;
int t = 0;
void mt(tree* a,int l,int r) {
    a->i = t - 1;
    if(l == r) {
        a->o = 1;
        a->v = 0;
        return;
    }
    a->l = &f[t++];
    a->left = t - 1;
    a->r = &f[t++];
    a->right = t - 1;
    int mid = (l + r) >> 1;
    mt(a->l,l,mid);mt(a->r,mid + 1,r);
    return;
}
int add(tree* a,int x,int v,int l,int r) {
    // cerr<<1;
    int mid = (l + r) >> 1;
    if(a->o) {
        a->v += v;
        return v;
    }
    if(mid < x) {
        int tmp = add(a->r,x,v,mid + 1,r);
        a->v += tmp;
        return tmp;
    }
    int tmp = add(a->l,x,v,l,mid);
    a->v += tmp;
    return tmp;
}
int check(tree* a,int l,int r,int rl,int rr) {
    // cerr<<l<<" "<<r<<"\n";
    int mid = (l + r) >> 1;
    if(a->o) {
        return a->v;
    }
    if(l == rl && r == rr) return a->v;
    if(rl > mid) return check(a->r,mid + 1,r,rl,rr);
    if(rr <= mid) return check(a->l,l,mid,rl,rr);
    return check(a->r,mid + 1,r,mid + 1,rr) + check(a->l,l,mid,rl,mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize((MAX << 2) + 5);
    mt(&f[t++],0,MAX);
    int ans = 0;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        tmp = tmp + ((int) 1e6);
        ans = ans + check(&f[0],0,MAX,tmp + 1,MAX);
        add(&f[0],tmp,1,0,MAX);
    }
    cout<<ans;
    return 0;
}