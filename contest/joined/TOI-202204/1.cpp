// Author : ysh
// 04/28/2022 Thu 21:22:35.98
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int p[502][502];
bool mark[502][502];
void check(int,int,int);
int a,b,c,d,e;
int color;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c>>d>>e;
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=b;j++) {
            cin>>p[i][j];
        }
    }
    color = p[c][d];
    check(c,d,e);
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=b;j++) {
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
void check(int x,int y,int now) {
    //printf("[%d][%d]\n",x,y);
    p[x][y] = now;
    mark[x][y] = 1;
    for(int i = 0;i<4;i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx > 0 && nx <= a && ny > 0 && ny <= b) {
            if(mark[nx][ny] != 1 && p[nx][ny] == color) check(nx,ny,now);
        }
    }
    return;
}