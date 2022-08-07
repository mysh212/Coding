// Author : ysh
// 08/06/2022 Sat 14:54:02.04
// https://cses.fi/problemset/task/1644
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

struct box{
    int i,v;
    box(int x = 0,int y = 0):
        i(x), v(y) {};
    bool operator<(const box &a)const {
        return v > a.v;
    }
    bool operator()(box a,box b) {
        return a.v < b.v;
    }
    bool operator()(box a) {
        return v < a.v;
    }
};
inline bool cp(box &a,box &b) {
    return a.v < b.v;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    multiset<box>s({box(-1,0)});
    int last = 0;
    int mmax = INT_MIN;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        tmp = last += tmp;
        debug(i,tmp);
        auto now = prev(s.end());
        bool o = 0;
        // cerr<<i<<"\n";
        // for(auto i : s) {
        //     cerr<<i.i<<" "<<i.v<<"\n";
        // }
        // cerr<<"\n";
        while(!(i - now->i >= b && i - now->i <= c)) {
            if(next(now) == s.begin()) {
                s.insert(box(i,tmp));
                o = 1;
                break;
            }
            now = prev(now);
            if(i - next(now)->i > c) s.erase(next(now));
        }
        // cerr<<now->i<<"\n";
        if(o) continue;
        s.insert(box(i,tmp));
        // for(auto i : s) {
        //     cerr<<i.i<<" "<<i.v<<"\n";
        // }
        // cerr<<"\n";
        // if(i == 2) return 1;
        mmax = max(mmax,tmp - now->v);
    }
    cout<<mmax;
    return 0;
}