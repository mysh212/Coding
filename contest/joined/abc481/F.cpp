// Author : ysh
// 2026/10/24 Sat 21:28:36
#include<bits/stdc++.h>
using namespace std;
const int R = 998244353;
#include<slow>
struct box {
    string x;
    int n;
    box():
        x(""), n(0) {};

    inline bool operator<(const box &a) const {
        if(a.n > n) return true;
        if(n > a.n) return false;
        return x < a.x;
    }

    inline box operator+(int a) {
        box t = box();
        t.x = x;
        t.n = n;
        t.x += ('0' + a);
        t.n++;
        return t;
    }

    inline operator int() {
        int64_t ans = 0;
        repo(&i, x) {
            ans = ans * 10 + (i & 15);
            ans %= R;
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;cin>>a>>b;
    vc<vc<pair<int, int>>>f(a);
    while(b--) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b, c});
        f.at(b).push_back({a, c});
    }

    vc<box>dt(a, box());
    priority_queue<pair<box, int>, vector<pair<box, int>>, greater<pair<box, int>>>q;
    q.push({box(), 0});
    while(!q.empty()) {
        auto [l, d] = q.top(); q.pop();

        if(dt.at(d).n != 0) continue;
        dt.at(d) = l;

        repo(&i, f.at(d)) {
            if(dt.at(i.first).n != 0) continue;
            q.push({l + i.second, i.first});
        }
    }

    re(i, 1, a) outl(int(dt.at(i)));
    return 0;
}