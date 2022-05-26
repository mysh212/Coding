// Author : ysh
// 05/21/2022 Sat 10:03:37.86
#include<bits/stdc++.h>
using namespace std;
#define int long long
int r;
struct box{
    int a,b,c,d;
};
void st(box);
box tt(box,box);
box check(box,int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n>>r) {
        n++;
        box a,b;
        a.c = a.b = a.d = 1;
        a.a = 0;
        if(n == 1) {
            cout<<1;
            return 0;
        }
        b = check(a,n - 1);
        box c;
        c.a = 0;
        c.b = 0;
        c.c = 1;
        c.d = 0;
        cout<<tt(b,c).c<<"\n";
    }
    return 0;
}
inline void st(box n) {
    cout<<n.a<<" "<<n.b<<"\n";
    cout<<n.c<<" "<<n.d<<"\n";
    return;
}
box check(box a,int now) {
    if(now == 1) return a;
    box tmp;
    tmp = check(a,(now >> 1));
    if(now & 1) {
        return tmp = tt(a,tt(tmp,tmp));
    }
    return tmp = tt(tmp,tmp);
}
inline box tt(box a,box b) {
    box tmp;
    tmp.a = ((a.a * b.a) + (a.b * b.c)) % r;
    tmp.b = ((a.a * b.b) + (a.b * b.d)) % r;
    tmp.c = ((a.c * b.a) + (a.d * b.c)) % r;
    tmp.d = ((a.c * b.b) + (a.d * b.d)) % r;
    return tmp;
}