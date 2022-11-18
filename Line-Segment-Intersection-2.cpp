// Author : ysh
// 11/15/2022 Tue 15:57:26.38
// https://cses.fi/problemset/task/2190
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int x,y;
    box(int x = 0,int y = 0):
        x(x), y(y) {};
    void input() {
        cin>>x>>y;
    }
    box operator-(box a) {
        return box(x - a.x,y - a.y);
    }
    int operator*(box a) {
        return x * a.x + y * a.y;
    }
    int operator/(box a) {
        return (x * a.y - y * a.x);
    }
};
inline int pos(int x) {
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}
inline bool on(box a,box b,box c) {
    box aa = b - a;
    box bb = c - a;
    if(aa / bb != 0) return 0;
    if(aa * bb < 0 || aa * bb > bb * bb) return 0;
    return 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;cin>>n;
    while(n--) {
        vector<box>f(4);
        for(auto &i : f) {
            i.input();
        }
        box aa = f.at(1) - f.at(0);
        box bb = f.at(2) - f.at(0);
        box cc = f.at(3) - f.at(0);
        box dd = f.at(3) - f.at(2);
        box ee = f.at(1) - f.at(2);
        box ff = f.at(0) - f.at(2);
        if(on(f.at(0),f.at(2),f.at(1)) || on(f.at(0),f.at(3),f.at(1)) || on(f.at(2),f.at(0),f.at(3)) || on(f.at(2),f.at(1),f.at(3))) cout<<"YES\n";
        else if(pos(bb / aa) != 0 && pos(dd / ee) != 0 && (pos(bb / aa) == pos(aa / cc) && pos(dd / ee) == pos(ff / dd))) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}