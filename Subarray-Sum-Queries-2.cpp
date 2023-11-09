// Author : ysh
// 2023/11/02 Thu 19:37:27
// https://cses.fi/problemset/task/1190
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int n;
    int l,r;
    int mmax,sig;
    box(int n = 0) {
        this->n = sig = mmax = l = r = n;
        return;
    }
    box operator=(int n) {
        return *this = box(n);
    }
    box operator=(box b) {
        n = b.n;
        l = b.l;
        r = b.r;
        mmax = b.mmax;
        sig = b.sig;
        return *this;
    }
    box operator-(box b) {
        return box(n - b.n);
    }
    box operator+(box b) {
        box tmp;
        tmp.l = max({0LL,l,sig + b.l});
        tmp.r = max({0LL,b.r,b.sig + r});
        tmp.mmax = max({mmax,b.mmax,0LL,r + b.l});
        tmp.sig = sig + b.sig;
        return tmp;
    }
    box operator+=(const box b) {
        n = n + b.n;
        l = l + b.l;
        r = r + b.r;
        mmax = mmax + b.mmax;
        sig = sig + b.sig;
        return *this;
    }
    box operator*(box b) {
        return *this;
    }
    box operator*(int b) {
        return *this;
    }
    box operator+=(int n) {
        return *this = box(this->n + n);
    }
    void print() {
        cerr<<"["<<n<<" "<<l<<" "<<r<<" "<<mmax<<" "<<sig<<"]\n";
        return;
    }
    friend ostream& operator<<(ostream& out,box b) {
        return out<<"["<<b.n<<" "<<b.l<<" "<<b.r<<" "<<b.mmax<<" "<<b.sig<<"]\n",out;
    }
};
#undef int
#include<seg_tree>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n = a;
    vector<box>f(a);
    for(box &i : f) {
        int tmp;cin>>tmp;
        i = box(tmp);
    }

    seg_tree<box>t(f);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;
        int det = b - f.at(a).n;
        t.add(a,a,det);
        f.at(a) = box(b);
        cout<<t.sum(0,n - 1).mmax<<"\n";
    }
    return 0;
}