// Author : ysh
// 02/24/2023 Fri  8:25:57.35
// https://cses.fi/problemset/task/1202
#include<bits/stdc++.h>
using namespace std;
const int R = (1e9) + 7;
#define int long long
#define INT_MAX __LONG_LONG_MAX__
struct box{
    int d,l,c,last;
    box(int d = 0,int l = 0,int c = 0,int last = 0):
        d(d), l(l), c(c), last(last) {};
    inline bool operator<(const box a) const {
        return l > a.l;
    }
    inline void print() {
        cerr<<"box: {"<<d<<","<<l<<","<<c<<","<<last<<"}\n";
        return;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a - 1).push_back({b - 1,c});
    }

    vector<int>dt(a,INT_MAX),mark(a),mmin(a,INT_MAX),mmax(a);
    priority_queue<box>q;
    q.emplace(0,0,0,-1);
    dt.at(0) = mmin.at(0) = mmax.at(0) = 0;
    mark.at(0) = 1;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        // now.print();
        int d = now.d;
        int l = now.l;
        int c = now.c;
        int last = now.last;
        if(dt.at(d) < l) continue;
        if(last != -1) {
            mmin.at(d) = min(mmin.at(last) + 1,mmin.at(d));
            mmax.at(d) = max(mmax.at(d),mmax.at(last) + 1);
        }
        if(dt.at(d) == l && last != -1) mark.at(d) = (mark.at(d) * 1LL + mark.at(last)) % R;
        if(dt.at(d) == l && last != -1) continue;
        if(dt.at(d) > l) dt.at(d) = l,mark.at(d) = mark.at(last);
        for(auto &i : f.at(d)) {
            q.push(box(i.first,l + i.second,c + 1,d));
        }
    }
    // for(int i : mark) cerr<<i<<" ";
    // cerr<<"\n";
    cout<<dt.at(a - 1)<<" "<<mark.at(a - 1)<<" "<<mmin.at(a - 1)<<" "<<mmax.at(a - 1);
    return 0;
}