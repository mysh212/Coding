// Author : ysh
// 10/21/2022 Fri 16:06:37.82
// https://tioj.ck.tp.edu.tw/problems/1069
#include<bits/stdc++.h>
using namespace std;
struct box{
    int t,x,y;
    box(int t = 0,int x = 0,int y = 0):
        t(t), x(x), y(y) {};
    inline bool operator<(const box &a) const {
        return t > a.t;
    }
};
inline int dt(int a,int b,int c,int d) {
    return (abs(a - c) + abs(b - d));
}
int check(int n,vector<box>&f) {
    vector<vector<int>>v(n);
    vector<bool>mark;
    vector<int>now(n,-1);
    function<bool(int)> ck = [&] (int x) {
        for(int &i : v.at(x)) {
            if(mark.at(i)) continue;
            mark.at(i) = 1;
            if(now.at(i) != -1) {
                if(!ck(now.at(i))) {
                    continue;
                }
            }
            now.at(i) = x;
            return 1;
        }
        return 0;
    };
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(i == j) continue;
            if(f[i].t < f[j].t && f.at(i).t + dt(f.at(i).x,f.at(i).y,f.at(j).x,f.at(j).y) <= f.at(j).t) {
                v.at(i).push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        mark = vector<bool>(n);
        if(ck(i)) ans++;
    }
    return n - ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<box>f(m);
        for(auto &i : f) {
            cin>>i.t>>i.x>>i.y;
        }
        // sort(f.rbegin(),f.rend());
        cout<<check(m,f)<<"\n";
    }
    return 0;
}