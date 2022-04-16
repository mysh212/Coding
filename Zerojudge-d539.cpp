// Author : ysh
// 04/03/2022 Sun 18:11:13.50
#include<bits/stdc++.h>
using namespace std;
vector<int>f(500000);
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
    a->max = max(a->l->max,a->r->max);
    return a;
}
int check(int l,int r,tree* a) {
    if(l > r) return INT_MIN;
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
    return max(check(l,(a->left + a->right) / 2,a->l),check((a->left + a->right) / 2+1,r,a->r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    mt(0,a - 1,&c[t++]);
    // for(int i = 0;i<a * 2 - 1;i++) {
    //     if(c[i].l == c[i].r) cout<<c[i].left<<" "<<c[i].max<<"\n";
    // }
    // system("pause");
    int m;cin>>m;
    int l,r;
    for(int i = 0;i<m;i++) {
        cin>>l>>r;
        if(l > r) swap(l,r);
        cout<<check(l - 1,r - 1,&c[0])<<"\n";
    }
    return 0;
}