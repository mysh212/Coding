// Author : ysh
// 01/22/2022 Sat 22:23:21.48
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
int c[10000][10000] = {};
int cnt = 2;
void check(int,int,int,int);
void pc(int,int);
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int a,b;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>c[i][j];
        }
    }
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            check(i,j,a,b);
        }
    }
}
void check(int a,int b,int n,int m) {
    if(c[a][b] != 0) return;
    c[a][b] = cnt;cnt++;
    pc(n,m);
    system("echo ...&&pause>nul");
    for(int i = 0;i<4;i++) {
        int x = a + xx[i];
        int y = b + yy[i];
        if(x>=0&&x<n&&y>=0&&y<m) {
            check(x,y,n,m);
        }
    }
}
void pc(int a,int b) {
    for(int i = 0;i<a;i++) {
        for(int k = 0;k<b;k++) {
            cout<<c[i][k]<<" ";
        }
        cout<<"\n";
    }
}
/*
5 5
1 0 0 0 1
0 0 1 0 0
0 0 1 0 0
0 0 1 0 0
0 0 1 0 0
*/