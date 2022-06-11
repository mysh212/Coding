// Author : ysh
// 06/10/2022 Fri 16:18:38.06
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long


vector<int>f(800000);
int t = 0;
struct tree{
    tree* l;
    tree* r;
    int max;
    int left;
    int right;
}c[1000000];
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
    a->max = a->l->max + a->r->max;
    return a;
}
int pluz(int l,int r,tree* a,int m,int n){
    if(l == r) {
        int tmp = a->max;
        a->max = n;
        return n - tmp;
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
    return check(l,(a->left + a->right) / 2,a->l) + check((a->left + a->right) / 2+1,r,a->r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mt(0,(n << 1) - 1,&c[t++]);
    vector<int>ff(n,-1),ll(n,-1);
    for(int i = 0;i<(n << 1);i++) {
        int tmp;
        cin>>tmp;
        tmp = tmp - 1;
        if(ff[tmp] == -1) {
            ff[tmp] = i;
            // debug(i);
        } else {
            ll[tmp] = i;
        }
    }
    debug(ff,ll);
    int ans = 0;
    // pluz(0,(n << 1) - 1,&c[0],3,1);
    // pluz(0,(n << 1) - 1,&c[0],2,1);
    // cerr<<check(0,(n << 1) - 1,&c[0]);
    // cerr<<check(3,3,&c[0]);
    // return 0;
    for(int i = 0;i<n;i++) {
        ans = ans + check(ff[i] + 1,ll[i] - 1,&c[0]);
        // printf("check(%d,%d)\n",ff[i] + 1,ll[i] - 1);
        pluz(0,(n << 1) - 1,&c[0],ff[i],1);
        pluz(0,(n << 1) - 1,&c[0],ll[i],1);
        debug(ans);
    }
    // for(int i = 0;i<10;i++) {
    //     cerr<<c[i].max<<" ";
    // }
    cout<<ans;
    return 0;
}