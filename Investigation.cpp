// Author : ysh
// 10/14/2022 Fri 19:46:20.97
// https://cses.fi/problemset/task/1202
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int R = 1e9 + 7;
// int mmax = INT_MIN,mmin = INT_MAX;
struct box{
    int l,d,c;

    box(int a = 0,int b = 0,int c = 0,int d = 0):
        l(a), d(b), c(c) {};
    inline bool operator<(const box a) const {
        return l < a.l;
    }
    inline bool operator() (box a,box b) {
        return a.l > b.l;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    priority_queue<box,vector<box>,box>q;
    vector<int>to(a),mmax(a),mmin(a,INT_MAX);
    int dt = LONG_LONG_MAX;
    vector<bool>mark(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
    }
    q.emplace(0,0,0);
    int ans = -1,r = 0;
    to.at(0) = 1;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int d = now.d;
        int l = now.l;
        int c = now.c;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        if(d == a - 1) {
            ans = l;
            break;
        }
        for(auto &i : f.at(d)) {
            if(i.first == a - 1) {
                if(dt > l + i.second) {
                    dt = l + i.second;
                    to.at(a - 1) = 0;
                    mmax.at(a - 1) = 0LL;
                    mmin.at(a - 1) = INT_MAX;
                }
            }
                to.at(i.first) = to.at(i.first) + to.at(d);
                mmax.at(i.first) = max({mmax.at(i.first),c + 1LL});
                mmin.at(i.first) = min({mmin.at(i.first),c + 1LL});
            q.emplace((l + i.second),i.first,c + 1);
        }
    }
    cout<<ans<<" "<<to.at(a  - 1) % R<<" "<<mmin.at(a - 1)<<" "<<mmax.at(a - 1);
    return 0;
}