// Author : ysh
// 05/11/2022 Wed 15:58:23.63
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INT_MAX LONG_LONG_MAX
#define INT_MIN LONG_LONG_MIN
int t = 1;
vector<int>f;
struct tree{
    tree* l;
    tree* r;
    int max;
    int min;
    int mi;
    int left;
    int right;
}c[600000];
tree* mt(int l,int r,tree* a){
    if(l == r) {
        a->l = a->r = a;
        a->left = a->right = l;
        a->min = f[l];
        a->mi = l;
        a->max = f[l];
        return a;
    }
    int mid = ((l + r) >> 1);
    a->l = mt(l,mid,&c[t++]);
    a->r = mt(mid + 1,r,&c[t++]);
    a->left = l;
    a->right = r;
    a->max = a->l->max + a->r->max;
    if(a->l->min <= a->r->min) {
        a->min = a->l->min;
        a->mi = a->l->mi;
        return a;
    }
    a->min = a->r->min;
    a->mi = a->r->mi;
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
pair<int,int> cm(int l,int r,tree* a) {
    if(l > r) return {INT_MAX,-1};
    int mid = ((a->left + a->right) >> 1);
    if(l == a->left&&r == a->right) {
        return {a->min,a->mi};
    }
    if(mid > r) return cm(l,r,a->l);
    if(mid < l) return cm(l,r,a->r);
    auto na = cm(l,mid,a->l);
    auto nb = cm(mid+1,r,a->r);
    if(na.first <= nb.first) {
        return na;
    }
    return nb;
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
int start(int l,int r,tree* a) {
    if(l > r) return -1;
    if(l == r) return f[l];
    auto now = cm(l,r,a);
    int mid = now.second;
    // printf("(%d,%d,%d) ",l,r,mid);
    int sl = check(l,mid - 1,a);
    int sr = check(mid + 1,r,a);
    if(sl > sr) return start(l,mid - 1,a);
    return start(mid + 1,r,a);
    // if(l == a->left&&r == a->right) {
    //     return {a->min,a->mi};
    // }
    // if(mid > r) return cm(l,r,a->l);
    // if(mid < l) return cm(l,r,a->r);
    // auto na = cm(l,mid,a->l);
    // auto nb = cm(mid+1,r,a->r);
    // if(na.first <= nb.first) {
    //     return na;
    // }
    // return nb;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    mt(0,n - 1,&c[0]);
    cout<<start(0,n - 1,&c[0]);
    return 0;
}