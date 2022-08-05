// Author : ysh
// 08/05/2022 Fri 10:04:31.65
#include<bits/stdc++.h>
using namespace std;
int c[100][100] = {};
bool mark[100][100] = {};
int xx[] = {1,0,-1,0};
int yy[] = {0,-1,0,1};
int a,b;
int check(int x,int y) {
    // cout<<c[x][y]<<" ";
    // if(!mark[x][y]) return 0;
    mark[x][y] = 1;
    int mmin = INT_MAX;
    int ni = -1;
    for(int i = 0;i <= 3;i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(!(nx < a && nx >= 0 && ny < b && ny >= 0)) continue;
        if(mark[nx][ny]) continue;
        if(c[nx][ny] < mmin) {
            mmin = c[nx][ny];
            ni = i;
        }
    }
    if(ni != -1) return check(x + xx[ni],y + yy[ni]) + c[x][y];
    else return c[x][y];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    int mmin = INT_MAX;
    int nx,ny;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>c[i][j];
            if(c[i][j] < mmin) {
                mmin = c[i][j];
                nx = i;
                ny = j;
            }
        }
    }
    cout<<check(nx,ny);
    return 0;
}