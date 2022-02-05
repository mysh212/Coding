// Author : ysh
// 02/03/2022 Thu 16:53:30.59
// http://choj.me/problem/00077
#include<bits/stdc++.h>
using namespace std;
int l = 0;
//int mark[1005][2009] = {};
const int xx[] = {1,-1,1,-1};
const int yy[] = {0,0,1,-1};
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int a[n][(n << 1) - 1] = {};
    queue<pair<int,int>>f;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<((i << 1) + 1);j++) {
            cin>>a[i][j];
            if(a[i][j] == 1) {
                f.push({i,j});
            }
        }
    }
    while(!f.empty()) {
        auto now = f.front();f.pop();
        int nx = now.first;
        int ny = now.second;
        

        
        bool t = 0;
        if(ny&1==1) t = 1;
        for(int i = 0;i<4;i++) {
            if(t == 0&&i == 3) break;
            if(t == 1&&i == 2) continue;
            int nnx = nx + yy[i];
            int nny = ny + xx[i];
            if(nnx<0||nny<0||nnx>=n||nny > (nnx << 1)) {
                l++;
                continue;
            }
            if(a[nnx][nny] == 0) {
                l++;
                continue;
            }
        }



    }
    cout<<l;
    return 0;
}