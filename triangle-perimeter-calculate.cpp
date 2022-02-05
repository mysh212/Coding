// Author : ysh
// 02/03/2022 Thu 16:53:30.59
// http://choj.me/problem/00077
#include<bits/stdc++.h>
using namespace std;
int l = 0;
int a[1005][2009] = {};
//int mark[1005][2009] = {};
const int xx[] = {1,-1,1,-1};
const int yy[] = {0,0,1,-1};
int n;
void check(int x,int y);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    queue<pair<int,int>>f;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<((i << 1) + 1);j++) {
            cin>>a[i][j];
            if(a[i][j] == 1) {
                f.push({i,j});
            }
        }
    }
    int ans = 0;
    while(!f.empty()) {
        auto now = f.front();f.pop();
        int nx = now.first;
        int ny = now.second;
        check(nx,ny);
        //cout<<l<<" ";
    }
    /*
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<((i << 1) + 1);j++) {
            cout<<mark[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    cout<<l;
    return 0;
}
void check(int x,int y) {
    // printf("%d %d\t",x,y);
    if(x<0||y<0||x>=n||y > (x << 1)) {
        // printf("%d %d\n",x,y);
        l++;
        return;
    }
    if(a[x][y] == 0) {
        // printf("%d %d\n",x,y);
        l++;
        return;
    }
    if(a[x][y] == -1) return;
    //printf("%d,%d\t",x,y);
    a[x][y] = -1;
    bool t = 0;
    if(y&1==1) t = 1;
    //printf("%d,%d\t",x,y);
    for(int i = 0;i<4;i++) {
        if(t == 0&&i == 3) break;
        if(t == 1&&i == 2) continue;
        int nx = x + yy[i];
        int ny = y + xx[i];
        //printf("==>%d,%d\t",nx,ny);
        check(nx,ny);
    }
    //printf("\n");
    return;
}