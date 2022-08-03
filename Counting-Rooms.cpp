// Author : ysh
// 07/31/2022 Sun 16:42:02.65
// https://cses.fi/problemset/task/1192
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {1,0,-1,0};
const int yy[] = {0,-1,0,1};
void check(int,int,bool);
int a,b;
int ans = 0;
vector<vector<bool>>f;
// vector<vector<bool>>f;
// vector<vector<bool>>mark;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        string c;cin>>c;
        for(int j = 0;j<b;j++) {
            f.at(i).at(j) = ((c.at(j) == '#' ? 1 : 0));
        }
    }
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(!f.at(i).at(j)) check(i,j,1);
        }
    }
    cout<<ans;
    return 0;
}
void check(int a,int b,bool t = 1) {
    if(!f.at(a).at(b)) {
        f.at(a).at(b) = 1;
        if(t) ans++;
        for(int i = 0;i<=3;i++) {
            int nx = a + xx[i];
            int ny = b + yy[i];
            if(nx < ::a && nx >= 0 && ny < ::b && ny >= 0) {
                check(nx,ny,0);
            }
        }
    }
    return;
}