// Author : ysh
// 2023/07/20 Thu 10:27:42
#include<bits/stdc++.h>
using namespace std;
#define yes "<(_ _)>\n"
#define no ">_<\n"
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a,vector<int>(b));
    vector<bool>ans(c,1);
    int t = 0;
    while(c--) {
        int a,b;cin>>a>>b;
        f[a][b] = ++t;
    }

    bool ok = 0;
    vector<pair<int,int>>now;
    for(int i = 0;i<a;i++) now.emplace_back(i,0);
    while(!ok) {
        sort(now.begin(),now.end(),[&] (pair<int,int>&a,pair<int,int>&b) {
            return f[a.first][a.second] < f[b.first][b.second];
        });
        int x = now.back().first;
        int y = now.back().second;
        now.pop_back();
        if(f[x][y] != 0) ans[f[x][y] - 1] = 0;
        f[x][y] = 0;
        queue<pair<int,int>>q;
        q.emplace(x,y);
        while(!q.empty()) {
            auto nnow = q.front();q.pop();
            int x = nnow.first;
            int y = nnow.second;
            if(f[x][y] > 0) now.emplace_back(x,y);
            if(f[x][y] != 0) continue;
            f[x][y] = -1;
            if(y == b - 1) {
                ok = 1;
                break;
            }
            for(int i = 0;i<=3;i++) {
                int nx = x + xx[i];
                int ny = y + yy[i];
                if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                q.emplace(nx,ny);
            }
        }
    }
    for(bool i : ans) cout<<(i ? yes : no);
    return 0;
}