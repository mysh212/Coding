// Author : ysh
// 07/16/2022 Sat  7:49:57
// https://judge.tcirc.tw/ShowProblem?problemid=d022
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int r = (int) 1e9 + 9;
struct box{
    int a,b;
    explicit box(int a,int b):
        a(a), b(b) {};
    box operator*(box x) {
        return box(a * x.a + ((b * x.b) << 1),a * x.b + b * x.a);
    }
    box operator+(box x) {
        return box(a + x.a,b + x.b);
    }
    box operator-(box x) {
        return box(a - x.a,b - x.b);
    }
    box operator%(int x) {
        return box(a % x,b % x);
    }
    box operator^(int x) {
        if(x == 1) return box(a,b);
        box tmp = box(a,b) ^ (x >> 1);
        if(x & 1) return ((tmp * tmp) % r * box(a,b)) % r;
        return (tmp * tmp) % r;
    }
    void check() {
        cerr<<a<<" + "<<b<<" * sqrt(2)\n";
    }
}c(box(0,0));
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int y;cin>>c.a>>c.b>>y;
    box ans = c ^  y;
    cout<<ans.a<<" "<<ans.b;
    return 0;
}
