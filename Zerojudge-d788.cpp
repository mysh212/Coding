// Author : ysh
// 06/11/2022 Sat  8:45:20.98
#include<bits/stdc++.h>
using namespace std;
vector<int>f(100000);
int t = 0;
struct tree{
    tree* l;
    tree* r;
    int max = 0;
    int left;
    int right;
};
vector<tree>c(200000);
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
    return check(l,(a->left + a->right) / 2,a->l) + check((a->left + a->right) / 2+1,r,a->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        t = 0;
        c.clear();
        c.resize((n << 1) + 5);
        mt(0,n,&c[t++]);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            tmp = tmp - 1;
            pluz(0,n,&c[0],tmp,1);
            cout<<check(tmp + 1,n,&c[0]) + 1<<"\n";
        }
    }
    return 0;
}