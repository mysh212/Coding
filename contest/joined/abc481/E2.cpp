// Author : ysh
// 2026/10/24 Sat 21:13:35
#include<bits/stdc++.h>
using namespace std;
struct box {
    int x, y, st;
    box(int x = 0, int y = 0, int st = 0):
        x(x), y(y), st(st) {};

    inline bool operator<(const box a) const {
        if(st != a.st) return st < a.st;
        return 1LL * y * a.x > 1LL * a.y * x;
    }

    friend istream& operator>>(istream& in, box &x) {
        in >> x.x >> x.y;
        x.st = (x.x < 0 || (x.x == 0 && x.y < 0));
        return in;
    }

    inline box operator-() {
        return box(-x, -y, st + 1);
    }

    inline box operator!() {
        return box(x, y, st | 2);
    }
};
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vc<box>f(n);
        cin>>f;

        sort(all(f));
        re(i, n) f.push_back(!f.at(i));

        int ans = 0;
        int r = 0;
        int m = n << 1;
        re(i, n) {
            while(r != m && f.at(r) < -f.at(i)) r++;
            ans = max(ans, r - i);
        }

        outl(ans);
    }
    return 0;
}