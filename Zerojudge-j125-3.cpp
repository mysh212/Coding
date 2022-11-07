// Author : ysh
// 10/30/2022 Sun 12:00:03.17
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>f;
#define att(a) f.at(a.first).at(a.second)
pair<int,int> ff(pair<int,int> a) {
    if(f.at(a.first).at(a.second) == a || att(a) == make_pair(-1,-1)) {
        att(a) = a;
        return a;
    }
    return f.at(a.first).at(a.second) = ff(f.at(a.first).at(a.second));
}
inline void mg(pair<int,int>a,pair<int,int>b) {
    att(ff(a)) = ff(b);
    return;
}
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
struct box{
    int a;
    pair<int,int>l,r;
    box(int a,pair<int,int>b,pair<int,int>c):
        a(a), l(b), r(c) {};
    inline bool operator<(const box x) const {
        return a > x.a;
    }
};
int n;
struct line{
    int x = 0,y = 0,z = 0;
    line(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
};
int walk(int r,vector<vector<int>>&v) {
    queue<line>q;
    vector<vector<bool>>mark(n,vector<bool>(n));
    q.emplace(0,0,0);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.x;
        int y = now.y;
        int t = now.z;
        if(x == n - 1 && y == n - 1) return t;
        if(mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || abs(v[x][y] - v[nx][ny]) > r) continue;
            q.emplace(nx,ny,t + 1);
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    ::f.resize(n,vector<pair<int,int>>(n,make_pair(-1,-1)));
    for(auto &i : f) for(int &j : i) cin>>j;
    vector<box>q;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            pair<int,int>now({i,j});
            for(int k = 0;k<=1;k++) {
                int nx = i + xx[k];
                int ny = j + yy[k];
                if(nx >= n || ny >= n) continue;
                q.push_back(box(abs(f[i][j] - f[nx][ny]),{i,j},{nx,ny}));
            }
        }
    }
    sort(q.begin(),q.end());
    int gap = 0;
    while(ff({n - 1,n - 1}) != ff({0,0}) && !q.empty()) {
        auto now = q.back();q.pop_back();
        mg(now.l,now.r);
        gap = now.a;
    }
    cout<<gap<<"\n";
    cout<<walk(gap,f);
    return 0;
}