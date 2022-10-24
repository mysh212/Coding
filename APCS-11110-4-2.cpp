// Author : ysh
// 10/24/2022 Mon 10:21:27.02
#include<bits/stdc++.h>
using namespace std;
bool c = 1;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
vector<vector<int>>f;
struct box{
    int x = 0,y = 0,z = 0;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
};
inline bool check(pair<int,int>&a,int b,int c,pair<int,int>d,bool e = 0) {
    int tmp = max(abs(b - c),d.first);
    if(a.first == tmp) {
        if(a.second > d.second) c = 1,a.second = d.second + 1;
        return 1;
    }
    if(a.first > tmp) {
        a.second = d.second + 1;
        a.first = tmp;
        c = 1;
        return 1;
    }
    return 0;
}
int n;
int walk(int r) {
    queue<box>q;
    q.emplace(0,0,0);
    vector<vector<bool>>mark(n,vector<bool>(n));
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
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || abs(f[x][y] - f[nx][ny]) > r) continue;
            q.emplace(nx,ny,t + 1);
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f.resize(n,vector<int>(n));
    vector<vector<pair<int,int>>>mark(n,vector<pair<int,int>>(n,{INT_MAX,0}));
    // vector<vector<int>>f(n,vector<int>(n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>f[i][j];
        }
    }
    mark[0][0].first = 0;
    for(int k = 0;k <= n;k++) {
        c = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) check(mark[i][j],f[i][j],f[i][j - 1],mark[i][j - 1]);
                else if(j == 0) check(mark[i][j],f[i][j],f[i - 1][j],mark[i - 1][j]);
                else check(mark[i][j],f[i][j],f[i - 1][j],mark[i - 1][j],check(mark[i][j],f[i][j],f[i][j - 1],mark[i][j - 1]));
            }
            for(int j = n - 2;j>=0;j--) {
                check(mark[i][j],f[i][j],f[i][j + 1],mark[i][j + 1]);
            }
        }
        for(int i = n - 2;i>=0;i--) {
            for(int j = 0;j<n;j++) {
                check(mark[i][j],f[i][j],f[i + 1][j],mark[i + 1][j]);
            }
        }
    }
    cout<<mark[n - 1][n - 1].first<<"\n"<<walk(mark[n - 1][n - 1].first);
    return 0;
}