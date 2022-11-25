// Author : ysh
// 11/25/2022 Fri 15:34:18.38
// https://tioj.ck.tp.edu.tw/problems/2254
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y,z;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
    inline bool operator<(const box a) const {
        return z < a.z;
    }
    inline void input() {
        cin>>x>>y>>z;
        x--;y--;
    }
};
int a,b;
bool check(int z,vector<box>&f) {
    vector<vector<int>>v(a);
    // vector<bool>to(a);
    for(box &i : f) {
        if(z < i.z) {
            v.at(i.x).push_back(i.y);
            // to.at(i.y) = 1;
            continue;
        }
        break;
    }
    // for(int i = 0;i<a;i++) {
    //     for(int &j : v.at(i)) {
    //         cerr<<i + 1<<" "<<j + 1<<"\n";
    //     }
    // }
    // cerr<<"\n";
    // vector<int>root;
    vector<int>dt(a,0);
    // for(int i = 0;i<a;i++) {
    //     if(!to.at(i)) dt.at(i) = 0;
    // }
    // debug(dt);
    for(int i = 0;i<a - 1;i++) {
        bool c = 0;
        for(int j = 0;j<a;j++) {
            for(int &k : v.at(j)) {
                if(dt.at(j) + 1 > dt.at(k)) {
                    dt.at(k) = dt.at(j) + 1;
                    c = 1;
                }
            }
        }
        // debug(dt);
        if(!c) return 1;
    }
    for(int j = 0;j<a;j++) {
        for(int &k : v.at(j)) {
            if(dt.at(j) + 1 < dt.at(k)) {
                return 0;
            }
        }
    }
    return 1;
}
int ck(int l,int r,vector<box>&f) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid,f)) return ck(l,mid,f);
    return ck(mid + 1,r,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<box>f(b);
    for(auto &i : f) {
        i.input();
    }
    sort(f.rbegin(),f.rend());
    cout<<ck(0,(int) 1e9,f);
    return 0;
}