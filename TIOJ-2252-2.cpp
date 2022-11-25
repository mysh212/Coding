// Author : ysh
// 11/25/2022 Fri  9:20:00.81
// https://tioj.ck.tp.edu.tw/problems/2252
#include<bits/stdc++.h>
using namespace std;
struct dot{
    int x,y;
    dot(int x = 0,int y = 0):
        x(x), y(y) {};
    inline dot operator-(dot a) {
        return dot(x - a.x,y - a.y);
    }
    inline int operator*(dot a) {
        return (x * a.x + y * a.y);
    }
    inline void input() {
        cin>>x>>y;
    }
    inline void print() {
        cerr<<x<<" "<<y<<"\n";
    }
    inline int dt(dot a,dot b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    inline double nearest(dot a,dot b,dot c) {
        dot v = b - c;
        // v.print();
        // x + n * v.x , y + n * v.y
        int aa = v.y * (c.x - a.x) + v.x * (c.y - a.y);
        int bb = (v.x * v.x + v.y * v.y);
        dot cc = (c.x + v.x * 1.0 * aa / bb,c.y + v.y * 1.0 * aa / bb);
        dot aaa = a - cc;
        dot bbb = b - cc;
        if(aaa * bbb > 0) return -1;
        // cerr<<aa<<" "<<bb<<"\n";
        return abs(aa * aa * 1.0 / bb);
    }
    inline double realdt(dot b,dot c) {
        double tmp = nearest(*this,b,c);
        if(abs(tmp - (-1)) > 0.001) return tmp;
        double bb = dt(*this,b);
        double cc = dt(*this,c);
        return min(bb,cc);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dot p;int n;
    p.input();
    cin>>n;
    double mmin = 1e18;
    dot last;last.input();
    for(int i = 0;i<n;i++) {
        dot tmp;tmp.input();
        mmin = min(mmin,p.realdt(last,tmp));
        last = tmp;
    }
    cout<<fixed<<setprecision(6)<<sqrt(mmin);
    return 0;
}