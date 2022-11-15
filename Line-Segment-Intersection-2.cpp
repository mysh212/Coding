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
        if(on(f.at(0),f.at(2),f.at(1))) cout<<"YES\n";
        else if(on(f.at(0),f.at(3),f.at(1))) cout<<"YES\n";
        else if(((f.at(2) - f.at(0)) / (f.at(1) - f.at(0))) * ((f.at(1) - f.at(0)) / (f.at(3) - f.at(0))) >= 0 && ((f.at(0) - f.at(2)) / (f.at(3) - f.at(2))) * ((f.at(3) - f.at(2)) / (f.at(1) - f.at(2))) >= 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}