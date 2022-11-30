// Author : ysh
// 11/29/2022 Tue 17:06:04.59
// https://cses.fi/problemset/task/1143
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x;
    box(int x = 0):
        x(x) {};
    inline void input() {
        cin>>x;
    }
    inline void print() {
        cout<<x<<"\n";
    }
    inline bool operator<(const box a) const {
        return x < a.x;
    }
    inline box operator+(const box a) const {
        return box(max(x,a.x));
    }
    inline box operator+=(const box a) {
        return box(x = (x + a.x));
    }
    inline box operator*(const int a) const {
        return box(x * a);
    }
};
#include<seg_tree>
int a,b;
int ck(int l,int r,int v,seg_tree<box>&t,int now = 1) {
    if(l == r && r == a - 1 && t.f.at(now).x < v) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(t.f.at(now << 1).x >= v) return ck(l,mid,v,t,now << 1);
    return ck(mid + 1,r,v,t,(now << 1) | 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<box>f(a);
    for(box &i : f) {
        i.input();
    }
    seg_tree<box>t(f);
    while(b--) {
        int tmp;cin>>tmp;
        int r = ck(0,a - 1,tmp,t);
        if(r != -1) t.add(r,r,-tmp);
        cout<<r + 1<<" ";
        // for(int i = 0;i<a;i++) {
        //     cout<<t.sum(i,i).x<<" ";
        // }
        // cout<<"\n";
    }
    return 0;
}