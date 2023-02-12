// Author : ysh
// 02/10/2023 Fri 21:58:22.62
// https://codeforces.com/contest/372/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int d,v,t;
    box(int d,int v,int t):
        d(d), v(v), t(t) {};
    inline bool operator<(const box &a) const {
        return t < a.t;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<box>f;
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.push_back(box(a - 1,b,c));
    }
    // sort(f.begin(),f.end());

    int last = 1;
    vector<vector<int>>g(2,vector<int>(a));
    for(int i = 0;i<b;i++) {
        int d = f.at(i).d;
        int v = f.at(i).v;
        int t = f.at(i).t;
        int step = c * (t - last);
        deque<pair<int,int>>q;
        for(int j = 0;j<a;j++) {
            int l = max(j - step,0LL);
            int r = min(a - 1,j + step);
            int now = g.at(i & 1).at(j);
            while(!q.empty() && q.back().second <= now) q.pop_back();
            q.emplace_back(j,now);
            auto n = q.front();
            while(!q.empty() && n.first < l) {
                q.pop_front();
                n = q.front();
            }
            assert(!q.empty());
            g.at(!(i & 1)).at(j) = n.second + (v - abs(j - d));
        }
        q.clear();
        for(int j = a - 1;j>=0;j--) {
            int l = max(j - step,0LL);
            int r = min(a - 1,j + step);
            int now = g.at(i & 1).at(j);
            while(!q.empty() && q.back().second <= now) q.pop_back();
            q.emplace_back(j,now);
            auto n = q.front();
            while(!q.empty() && n.first > r) {
                q.pop_front();
                n = q.front();
            }
            assert(!q.empty());
            g.at(!(i & 1)).at(j) = max(g.at(!(i & 1)).at(j),n.second + (v - abs(j - d)));
        }
        last = t;
        // for(int i : g.at(!(i & 1))) cerr<<i<<" ";
        // cerr<<"\n";
    }
    cout<<*max_element(g.at(b & 1).begin(),g.at(b & 1).end());
    return 0;
}