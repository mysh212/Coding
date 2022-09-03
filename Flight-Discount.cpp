// Author : ysh
// 08/30/2022 Tue 13:34:45.06
// https://cses.fi/problemset/task/1195
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y,z;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
    bool operator<(box a) {
        return x < a.x;
    }
    bool operator() (box a,box b) {
        return a.x < b.x;
    }
};
const long long R = 1e14;
#define int long long
bool c = 0;
inline bool cp(int l,int r) {
    if(l < r) {
        c = 1;
        return 1;
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f[a];
    vector<pair<int,int>>to[a];
    vector<int>dt(a,R);
    vector<int>dtr(a,R);
    dt[0] = 0;
    dtr[a - 1] = 0;
    function<int()> check = [&] () {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,0);
        vector<bool>mark(a);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int d = now.second;
            int l = now.first;
            if(mark[d]) continue;
            dt[d] = l;
            mark[d] = 1;
            for(auto i : f[d]) {
                q.emplace(l + i.second,i.first);
            }
        }
        q.emplace(0,a - 1);
        mark.clear();
        mark.resize(a);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int d = now.second;
            int l = now.first;
            if(mark[d]) continue;
            dtr[d] = l;
            mark[d] = 1;
            for(auto i : to[d]) {
                q.emplace(l + i.second,i.first);
            }
        }
        // for(int k = 0;k<a - 1;k++) {
        //     c = 0;
        //     for(int i = 0;i<a;i++) {
        //         for(auto &j : f[i]) {
        //             if(dt[i] == R) continue;
        //             dt[j.first] = min(dt[j.first],dt[i] + j.second,cp);
        //         }
        //     }
        //     if(!c) break;
        // }
        // for(int k = 0;k<a - 1;k++) {
        //     c = 0;
        //     for(int i = 0;i<a;i++) {
        //         for(auto &j : f[i]) {
        //             if(dtr[j.first] == R) continue;
        //             dtr[i] = min(dtr[i],dtr[j.first] + j.second,cp);
        //         }
        //     }
        //     if(!c) break;
        // }
        debug(dt,dtr);
        int ans = R;
        for(int i = 0;i<a;i++) {
            for(auto &j : f[i]) {
                if(dt[i] == R || dtr[j.first] == R) continue;
                ans = min(ans,dt[i] + (j.second >> 1) + dtr[j.first]);
            }
        }
        return ans;
    };
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a - 1].push_back({b - 1,c});
        to[b - 1].push_back({a - 1,c});
    }
    cout<<check();
    return 0;
}