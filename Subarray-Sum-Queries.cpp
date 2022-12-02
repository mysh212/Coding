// Author : ysh
// 12/02/2022 Fri  9:50:54.20
// https://cses.fi/problemset/task/1190
// NF
#include<bits/stdc++.h>
using namespace std;
struct box{
    int mmin,mmax;
    box(int x = 0):
        mmin(x), mmax(0) {};
    box(int x,int y):
        mmin(x), mmax(y) {};
    inline box operator+(box a) {
        return box(mmin + a.mmin,max(mmax,mmin + a.mmin));
    }
    inline box operator+=(box a) {
        return *this = box(mmin + a.mmin,0);
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
    for(box &i : f) {
        int tmp;cin>>tmp;
        i = box(tmp);
    }
    seg_tree<box>t(f);
    while(b--) {
        int aa,bb;cin>>aa>>bb;
        aa--;
        int tmp = bb - f.at(aa).mmin;
        f.at(aa) = box(bb);
        t.add(aa,aa,box(tmp));
        cout<<t.sum(0,b).mmax<<"\n";
    }
    return 0;
}