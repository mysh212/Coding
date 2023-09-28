// Author : ysh
// 2023/07/12 Wed 09:23:31
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<bool>>f(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            char tmp;cin>>tmp;
            f.at(i).at(j) = (tmp == '.');
        }
    }

    int ans = 0;
    queue<pair<int,int>>q;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            if(f.at(i).at(j)) q.push({i,j}),ans++;
            while(!q.empty()) {
                auto now = q.front();q.pop();
                int x = now.first;
                int y = now.second;

                f.at(x).at(y) = 0;
                for(int i = 0;i<=3;i++) {
                    int nx = x + xx[i];
                    int ny = y + yy[i];
                    if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}