// Author : ysh
// 05/06/2023 Sat 20:43:47.19
#include<bits/stdc++.h>
using namespace std;
int xx[] = {-1,0,1,0};
int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>b>>a;
    vector<vector<bool>>f(a,vector<bool>(b)),mark(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            char tmp;cin>>tmp;
            if(tmp == '#') mark.at(i).at(j) = 1;
            if(tmp == 'P') f.at(i).at(j) = 1;
        }
    }

    function<bool(int,int)> check = [&] (int x,int y) {
        if(mark.at(x).at(y)) return false;
        mark.at(x).at(y) = 1;
        bool c = f.at(x).at(y);
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
            c = c | check(nx,ny);
        }
        return c;
    };

    bool now = 0;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(!mark.at(i).at(j) && check(i,j)) {
                if(now) {
                    cout<<"No";
                    return 0;
                }
                now = 1;
            }
        }
    }
    cout<<"Yes";
    return 0;
}