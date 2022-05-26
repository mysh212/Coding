// Author : ysh
// 05/05/2022 Thu 17:49:00.55
// https://203.64.159.117/ShowProblem?problemid=a268
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = (int) 1e5 + 5;
vector<int>g(MAX);
vector<int>f(MAX);
int t = 1;
struct tree{
    tree* l;
    tree* r;
    int max;
    int left;
    int right;
}c[250000];
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
    return check(l,(a->left + a->right) / 2,a->l) +check((a->left + a->right) / 2+1,r,a->r);
}
int pluz(int l,int p,tree* a) {
    if(l == a->left && l == a->right) {
        a->max += p;
        return p;
    }
    int mid = ((a->left + a->right) >> 1);
    if(l <= mid) {
        a->max += p;
        return pluz(l,p,a->l);
    }
    if(l > mid) {
        a->max += p;
        return pluz(l,p,a->r);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;cin>>n;
    for(int i = 0;i<n;i++) {
        cin>>g[i];
    }
    int ans = 0;
    mt(0,MAX - 1,&c[0]);
    // pluz(3,1,&c[0]);
    // pluz(4,1,&c[0]);
    // pluz(5,1,&c[0]);
    // cout<<check(3,5,&c[0]);
    // return 0;
    for(int i = 0;i<n;i++) {
        pluz(g[i],g[i],&c[0]);
        ans = ans + check(0,g[i] - 1,&c[0]);
    }
    cout<<ans;
    return 0;
}