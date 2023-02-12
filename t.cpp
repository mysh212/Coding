// Author : ysh
// 02/10/2023 Fri 19:27:55.19
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<array<int,3>>f(b);
    for(int i = 0;i<b;i++) {
        cin>>f[i][0]>>f[i][1]>>f[i][2];
    }
    sort(f.begin(),f.end(),[] (array<int,3>&a,array<int,3>&b) {
        return a[2] < b[2];
    });

    vector<vector<int>>g(2,vector<int>(a + 1));
    int last = 1;
    for(int i = 0;i<b;i++) {
        int d = f[i][0];
        int v = f[i][1];
        int t = f[i][2];
        int step = (c * abs(t - last));
        deque<pair<int,int>>q({{1,g.at(i & 1).at(0)}});
        for(int j = 2;j<=a;j++) {
            int l = max(1,j - step);
            int r = min(a,j + step);
            auto now = q.back();
            while(!q.empty() && now.first < l) {
                q.pop_back();
                now = q.back();
            }
            debug(now);
            g.at(!(i & 1)).at(j) = now.second + (v - abs(d - j));
            while(!q.empty() && q.back().second < g.at(i & 1).at(j)) {
                q.pop_back();
            }
            q.emplace_back(j,g.at(i & 1).at(j));
        }
        q.clear();
        q.push_back({a,g.at(i & 1).at(a)});
        for(int j = a - 1;j>0;j--) {
            int l = max(1,j - step);
            int r = min(a,j + step);
            auto now = q.back();
            while(!q.empty() && now.first > r) {
                q.pop_back();
                now = q.back();
            }
            g.at(!(i & 1)).at(j) = max(g.at(!(i & 1)).at(j),now.second + (v - abs(j - d)));
            while(!q.empty() && q.back().second < g.at(i & 1).at(j)) {
                q.pop_back();
            }
            q.emplace_back(j,g.at(i & 1).at(j));
        }
        for(int i = 1;i<=a;i++) {
            g.at(!(i & 1)).at(i) = max(g.at(!(i & 1)).at(i),g.at(i & 1).at(i) + (v - abs(d - i)));
        }
        last = t;
        for(int &j : g[i & 1]) cerr<<j<<" ";
        cerr<<"\n";
    }
    cout<<*max_element(g[!(b & 1)].begin(),g[!(b & 1)].end());
    return 0;
}