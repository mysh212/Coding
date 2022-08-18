// Author : ysh
// 08/17/2022 Wed 14:20:06.30
// https://cses.fi/problemset/task/1144/
#include<bits/stdc++.h>
using namespace std;
// vector<int>f;
int t = 0;
vector<int>m;
struct box{
    bool a;
    int b,c;
    box(char x = ' ',int y = 0,int z = 0) {
        a = (x == '?' ? 1 : 0);
        b = y;
        c = z;
        if(!a) m.push_back({c,0});
    }
};
struct tree{
    tree* l;
    tree* r;
    int max = 0;
    int left;
    int right;
};
vector<tree>c(1);
tree* mt(int l,int r,tree* a){
    if(l == r) {
        a->l = a->r = a;
        a->left = a->right = l;
        // a->max = f[l];
        return a;
    }
    int mid = ((l + r) >> 1);
    c.push_back(tree());
    a->l = mt(l,mid,&c[t++]);
    c.push_back(tree());
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
    if(mid >= r) return check(l,r,a->l);
    if(mid < l) return check(l,r,a->r);
    return check(l,(a->left + a->right) / 2,a->l) + check((a->left + a->right) / 2+1,r,a->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>ff(a);
    for(int &i : ff) {
        cin>>i;
        m.push_back(i);
    }
    queue<box>q;
    for(int i = 0;i<b;i++) {
        char a;cin>>a;
        int b,c;cin>>b>>c;
        q.push(box(a,b,c));
    }
    int r = 0;
    sort(m.begin(),m.end());
    m.resize(unique(m.begin(),m.end()) - m.begin());
    // for(auto &i : m) {
    //     cout<<i.first<<" ";
    // }
    int n = m.size();
    // f.resize(n + 1);
    mt(0,n - 1,&c[t++]);
    for(int i : ff) {
        pluz(0,n - 1,&c[0],m[i],1);
    }
    while(!q.empty()) {
        auto now = q.front();q.pop();
        bool a = now.a;
        int x,y;x = now.b;y = now.c;
        if(a) {
            cout<<check(lower_bound(m.begin(),m.end(),(x >= 0 ? x : 0)) - m.begin(),(upper_bound(m.begin(),m.end(),y) - 1) - m.begin(),&c[0])<<"\n";
            continue;
        }
        pluz(0,n - 1,&c[0],m[ff.at(x)],-1);
        pluz(0,n - 1,&c[0],m[ff.at(x) = y],1);
    }
    return 0;
}