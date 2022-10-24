// Author : ysh
// 10/23/2022 Sun 21:05:37.07
// TLE
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {1,0,-1,0};
const int yy[] = {0,1,0,-1};
struct box{
    int x,y,z,l;
    box(int x = 0,int y = 0,int z = 0,int l = 0):
        x(x), y(y), z(z), l(l) {};
    inline bool operator<(const box a) const {
        if(z == a.z) return l > a.l;
        return z > a.z;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>f[i][j];
        }
    }
    priority_queue<box>q;
    q.emplace(0,0,0,0);
    vector<vector<bool>>mark(n,vector<bool>(n));
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int x = now.x;
        int y = now.y;
        int z = now.z;
        int l = now.l;
        // if(mark.at(x).at(y)) continue;
        // mark.at(x).at(y) = 1;
        if(x == n - 1 && y == n - 1) {
            cout<<z<<"\n"<<l;
            return 0;
        }
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            q.emplace(nx,ny,max(z,abs(f[x][y] - f[nx][ny])),l + 1);
        }
    }
    return 0;
}