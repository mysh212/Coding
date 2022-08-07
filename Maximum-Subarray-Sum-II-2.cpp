// Author : ysh
// 08/07/2022 Sun 10:19:56.09
// https://cses.fi/problemset/task/1644/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>f(100000);
int t = 0;
struct tree{
    tree* l;
    tree* r;
    int max = INT_MIN;
    int left;
    int right;
};
vector<tree>c(800000);
tree* mt(int l,int r,tree* a){
    if(l == r) {
        a->l = a->r = a;
        a->left = a->right = l;
        a->max = f[l];
        return a;
    }
    int mid = ((l + r) >> 1);
    a->l = mt(l,mid,&c[t++]);
    a->r = mt(mid + 1,r,&c[t++]);
    a->left = l;
    a->right = r;
    a->max = min(a->l->max,a->r->max);
    return a;
}
int pluz(int l,int r,tree* a,int m,int n){
    l = a->left;
    r = a->right;
    if(l == r) {
        // int tmp = a->max;
        a->max += n;
        return n;
    }
    int mid = ((l + r) >> 1);
    if(mid >= m) {
        int tmp = pluz(l,mid,a->l,m,n);
        a->max += tmp;
        return tmp;
    }
    int tmp = pluz(mid + 1,r,a->r,m,n);
    a->max += tmp;
    return tmp;
}
int check(int l,int r,tree* a) {
    if(l > r) return 0;
    // printf("(%d %d) (%d %d)\n",l,r,a->left,a->right);
    int mid = ((a->left + a->right) >> 1);
    // if(l == r) {
    //     printf("return %d\n",a->max);
    //     return a->max;
    // }
    if(l == a->left&&r == a->right) {
        // printf("return %d\n",a->max);
        return a->max;
    }
    if(mid > r) return check(l,r,a->l);
    if(mid < l) return check(l,r,a->r);
    return min(check(l,(a->left + a->right) / 2,a->l),check((a->left + a->right) / 2+1,r,a->r));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,d;cin>>a>>b>>d;
    // vector<int>f(a);
    f.resize(a);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }
    for(int i : f) cout<<i<<" ";
    cout<<"\n";
    mt(0,a - 1,&c[t++]);
    int mmax = INT_MIN;
    for(int i = 0;i<a;i++) {
        mmax = max(mmax,f[i] - check((i - d < 0 ? 0 : i - d),(i - b < 0 ? 0 : i - b),&c[0]));
    }
    cout<<mmax;
    return 0;
}