// Author : ysh
// 11/06/2022 Sun 10:27:48.68
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,-1,1,-1,0,1};
const int yy[] = {-1,-1,-1,0,0,1,1,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    vector<vector<int>>mark(n,vector<int>(n));
    for(auto &i : f) for(int &j : i) {char now;cin>>now;if(now != '*') {int tmp;cin>>tmp;j = -tmp;}}
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(f[i][j] != 0) {
                mark[i][j] = f[i][j];
                continue;
            }
            for(int k = 0;k<=7;k++) {
                int nx = i + xx[k];
                int ny = j + yy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                mark[i][j] += -f[nx][ny];
            }
        }
    }
    for(auto &i : mark) {for(int &j : i) cout<<j<<" "; cout<<"\n";}
    return 0;
}