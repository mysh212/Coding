// Author : ysh
// 11/15/2022 Tue  9:58:42.96
// https://tioj.ck.tp.edu.tw/problems/2252
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y;
    box(int x,int y):
        x(x), y(y) {};
};
double dt(box a,box b,box c) {
    double aa,bb;
    aa = (a.y - b.y) / (a.x - b.x);
    bb = a.y - (aa * a.x);
    return (abs(a * c.x + bb - c.y)) / sqrt(aa * aa + (-1) * (-1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,y,n;cin>>x>>y>>n;
    vector<box>f(n);
    while(n--) {
        
    }
}