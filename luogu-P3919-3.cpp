// Author : ysh
// 02/11/2023 Sat 21:49:02.77
// https://www.luogu.com.cn/problem/P3919
#include<bits/stdc++.h>
using namespace std;
#include<fast>
struct node{
    int n;
    node* l;
    node* r;
    node(node *a) {
        l = a->l;
        r = a->r;
        this->n = a->n;
    }
    node() {
        n = 0;
        l = nullptr;
        r = nullptr;
    }
    node(int a) {
        n = a;
        l = nullptr;
        r = nullptr;
    }
};
class seg_tree{
    public:
    vector<int>f;
    int n;
    
    seg_tree(vector<int>&v) {
        n = v.size();
        // mt(v);
    }
    
    node* mt(vector<int>&v,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl == nr) return new node(v.at(nl));
        int mid = (nl + nr) >> 1;
        node* t = new node;
        t->l = mt(v,nl,mid);
        t->r = mt(v,mid + 1,nr);
        // assert(t->l && t->r);
        return t;
    }
    
    node* get(node* t,int p,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl == nr) return t;
        int mid = (nl + nr) >> 1;
        // assert(t->r);
        // assert(t->l);
        if(p >= nl && p <= mid) return get(t->l,p,nl,mid);
        if(p > mid && p <= nr) return get(t->r,p,mid + 1,nr);
        exit(-2);
    }
    
    node* add(node* t,int p,int v,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl == nr) return new node(v);
        node* nt = new node(t);
        nt->l = t->l;nt->r = t->r;
        int mid = (nl + nr) >> 1;
        if(p >= nl && p <= mid) nt->l = add(t->l,p,v,nl,mid);
        if(p > mid && p <= nr) nt->r = add(t->r,p,v,mid + 1,nr);
        // nt->n = nt->l->n + nt->r->n;
        // assert(nt->l && nt->r);
        return nt;
    }
};
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    vector<node*>f;
    int a,b;cin>>a>>b;
    vector<int>v(a);
    for(int &i : v) {
        cin>>i;
    }
    seg_tree t(v);
    f.push_back(t.mt(v));
    while(b--) {
        int a,b;cin>>a>>b;
        if(b == 1) {
            int c,d;cin>>c>>d;
            c--;
            f.push_back(t.add(f.at(a),c,d));
        }
        if(b == 2) {
            int c;cin>>c;
            c--;
            cout<<t.get(f.at(a),c)->n<<"\n";
            f.push_back(f.at(a));
        }
    }
    return 0;
}