// Author : ysh
// 2026/10/30 Fri 16:10:34
// https://tioj.ck.tp.edu.tw/problems/1178
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define int int64_t
struct dot {
    int x, y;

    dot(int x = 0, int y = 0):
        x(x), y(y) {};

    inline dot operator*(dot a) {
        return dot(x * a.x, y * a.y);
    }

    inline int operator/(dot a) {
        return x * a.y - y * a.x;
    }

    inline bool operator<(const dot &a) const {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }

    inline dot operator-(const dot &a) const {
        return dot(x - a.x, y - a.y);
    }

    inline friend istream& operator>>(istream& in, dot &x) {
        in>>x.x>>x.y;
        return in;
    }

    inline friend ostream& operator<<(ostream& in, dot &x) {
        in<<x.x<<" "<<x.y;
        return in;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<dot>f(n);
    for(dot &i : f) cin>>i;

    sort(f.begin(), f.end());
    vector<dot>ans(f.begin(), f.begin() + 2);
    dot last = ans.back() - ans.front();
    for(int k = 0;k<=1;k++) {
        for(int i = 2;i<n;i++) {
            // #define l last
            dot r = f.at(i) - ans.at(ans.size() - 2);
            // debug(r.x, r.y);
            // debug(last.x, last.y);
            // debug(last / r);
    
            if(last / r >= 0) ans.pop_back();
            last = f.at(i) - ans.back();
            ans.push_back(f.at(i));
        }
        reverse(f.begin(), f.end());
    }

    for(dot &i : ans) {debug(i.x, i.y);}
    cout<<ans.size() - 1;
    return 0;
}