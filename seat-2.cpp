// Author : ysh
// 06/16/2022 Thu 15:07:17.58
// https://192.168.193.20/problem/36
#include<bits/stdc++.h>
using namespace std;
#define int long long
int r;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    class t{
        public:
        int a,b,c,d;
        explicit t(int a,int b,int c,int d):
            a(a), b(b), c(c), d(d) {};
        inline t operator*(t x) {
            if(x.a == x.b && x.b == x.c && x.c == x.d && x.d == 1) return t(a,b,c,d);
            return t((a * x.a + b * x.c) % r,(a * x.b + b * x.d) % r,(c * x.a + d * x.c) % r,(c * x.b + d * x.d) % r);
        }
        t check(int y) {
            // cerr<<y;
            if(y == 1) return t(0,1,1,1);
            t now = check(y >> 1);
            if(y & 1) return (now * now) * t(0,1,1,1);
            return (now * now);
        }
        t show(t x) {
            cerr<<x.a<<" "<<x.b<<"\n";
            cerr<<x.c<<" "<<x.d<<"\n";
            return x;
        }
    };
    // r = 10000;
    // t c = t(0,0,0,0);
    // c.show(t(1,2,3,4) * t(1,2,3,4));
    // return 0;
    int a;
    while(cin>>a>>r) {
        a = a + 1;
        t c = t(0,1,1,1);
        t now = c.check(a);
        // now.show(now);
        cout<<(now * t(1,0,1,0)).a<<"\n";
    }
    return 0;
}