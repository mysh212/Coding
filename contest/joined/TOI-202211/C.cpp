// Author : ysh
// 11/30/2022 Wed 21:57:11.30
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(a),g(a,box(1e9));
    // a = a - 2;
    for(int i = 1;i<a - 1;i++) {
        cin>>f.at(i).x;
    }
    seg_tree<box>t(g);
    t.add(0,0,box(1));
    for(int i = 0;i<a;i++) cerr<<t.sum(i,i).x;
    // f.push_back(0);
    g.at(0) = box(0);
    for(int i = 1;i<a;i++) {
        g.at(i) = t.sum(max(i - b,0),i - 1);
        // for(int j = i - 1;j >= max(i - b,0);j--) {
        //     g.at(i) = max(g.at(i),g.at(j));
        // }
        if(i <= b) g.at(i) = box(max(g.at(i).x,0));
        g.at(i).x = g.at(i).x + f.at(i).x;
        cerr<<g.at(i).x<<" "<<t.sum(i,i).x<<" ";
        t.add(i,i,box(g.at(i) + (int) 1e9));
    }
    cout<<g.at(a - 1).x;
    return 0;
}