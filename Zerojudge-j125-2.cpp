// Author : ysh
// 10/24/2022 Mon  8:39:12.07
#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>f;
vector<vector<int>>v;
int n;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
// inline pair<int,int> at(pair<int,int>a) {
//     return f.at(a.first).at(a.second);
// }
queue<pair<int,int>>re;
struct box{
    int x = 0,y = 0,z = 0;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
};
#define att(a) f.at(a.first).at(a.second)
pair<int,int> ff(pair<int,int> a) {
    if(f.at(a.first).at(a.second) == a || att(a) == make_pair(-1,-1)) {
        att(a) = a;
        return a;
    }
    re.push(a);
    return f.at(a.first).at(a.second) = ff(f.at(a.first).at(a.second));
}
inline void mg(pair<int,int>a,pair<int,int>b) {
    re.push(a);re.push(b);
    att(ff(a)) = ff(b);
    return;
}
inline bool check(int r) {
    for(int i = 1;i<n;i++) {
        if(abs(v.at(0).at(i) - v.at(0).at(i - 1)) <= r) mg({0,i},{0,i - 1});
        if(abs(v.at(i).at(0) - v.at(i - 1).at(0)) <= r) mg({i,0},{i - 1,0});
    }
    for(int i = 1;i<n;i++) {
        for(int j = 1;j<n;j++) {
            if(abs(v.at(i).at(j) - v.at(i - 1).at(j)) <= r) mg({i,j},{i - 1,j});
            if(abs(v.at(i).at(j) - v.at(i).at(j - 1)) <= r) mg({i,j},{i,j - 1});
        }
    }
    // cerr<<f[0][0].first<<" "<<f[n - 1][n - 1].first;
    if(ff({n - 1,n - 1}) == ff({0,0})) return 1;
    return 0;
}
int walk(int r) {
    queue<box>q;
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
inline int ck() {
    int l = 0,r = 1e6;
    while(l != r) {
        // cerr<<l<<" "<<r<<"\n";
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
        // f = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(n,{-1,-1}));
        while(!re.empty()) {
            auto now = re.front();re.pop();
            att(now) = {-1,-1};
        }
    }
    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    v.resize(n,vector<int>(n));
    f.resize(n,vector<pair<int,int>>(n,{-1,-1}));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>v[i][j];
        }
    }
    int tmp = ck();
    cout<<tmp<<"\n"<<walk(tmp);
    return 0;
}