// Author : ysh
// 02/01/2022 Tue 16:10:11.91
// https://zerojudge.tw/ShowProblem?problemid=c292
#include<bits/stdc++.h>
using namespace std;
int c[51][51] = {};
void check(int,int,int,int,int,int,int,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,d;cin>>n>>d;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>c[i][j];
        }
    }
    int x,y;
    if(d == 0) {
        x=n;y=0;
    }
    if(d == 1) {
        x=0;y=0;
    }
    if(d == 2) {
        x=0;y=n;
    }
    if(d == 3) {
        x=n;y=n;
    }
    int mid = (n >> 1) + 1;
    check(mid,mid,d,0,x,y,1,1);

}
void check(int i,int j,int d,int t,int x,int y,int move,int movet) {
    if(i == x&&j == y) {
        cout<<c[i][j]<<"\n";
        return;
    }
    if(move == 1) {
        if(d == 0&&t == 0) {
            check(i-1,j,t+1,x,y,move-1);
        }
        if(d == 0&&t == 1) {
            check(i-1,j,t+1,x,y,move-1);
        }
    }
}