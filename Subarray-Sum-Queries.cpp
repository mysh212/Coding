// Author : ysh
// 12/02/2022 Fri  9:50:54.20
// https://cses.fi/problemset/task/1190
// NF
#include<bits/stdc++.h>
using namespace std;
struct box{
    int mmin,mmax,v;
    box(int x = 0):
        mmin(x), mmax(x), v(max(0,x)) {};
    box(int x,int y,int v):
        mmin(x), mmax(y), v(v) {};
    inline box operator+(box a) {
        return box(min(mmin,a.mmin),max(mmax,a.mmax),max(a.v,a.mmax - mmin));
    }
    inline box operator+=(box a) {
        return *this = box(mmin + a.mmin);
    }
    inline box operator*(int a) {
        return *this;
    }
};
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(a);
    int last = 0;
    for(box &i : f) {
        int tmp;cin>>tmp;
        i = box(last += tmp);
    }
    seg_tree<box>t(f);
        cout<<t.sum(0,b - 1).mmax<<"\n";
    while(b--) {
        int aa,bb;cin>>aa>>bb;
        aa--;
        int tmp = bb - f.at(aa).mmin;
        f.at(aa) = box(bb);
        t.add(aa,b - 1,box(tmp));
        cout<<t.sum(0,b - 1).mmax<<"\n";
    }
    return 0;
}