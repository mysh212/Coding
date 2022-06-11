// Author : ysh
// 05/31/2022 Tue 11:17:57.13
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
struct box{
    int x;
    int y;
    int t;
};
    vector<vector<vector<bool>>>c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    c.resize(a,vector<vector<bool>>(b,vector<bool>(1000)));
    bool h[a][b] = {};
    int tmp = 0;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>tmp;
            h[i][j] = c[i][j][0] = tmp;
        }
    }
    int t = 1;
    while(1) {
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                if(c[i][j][t - 1] == 1) {
                    for(int k = 0;k<=3;k++) {
                        int x = i + xx[k];
                        int y = j + yy[k];
                        if(x >= 0 && x < a && y >= 0 && y < b) {
                            c[x][y][t] = 1;
                        }
                    }
                }
            }
        }
        bool s = 0;
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                // cout<<c[i][j][t]<<" ";
                if(!c[i][j][t]) {
                    s = 1;
                    break;
                }
            }
            if(s) break;
            // cout<<"\n";
        }
        t++;
        if(!s) break;
        // cout<<std::flush;
        // system("pause");
        // cout<<1;
    }
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            c[i][j][0] = h[i][j];
        }
    }
    int d,e,f,g;cin>>d>>e;
    cin>>f>>g;
    d--;e--;f--;g--;
    queue<tuple<int,int,int>>q;
    q.push(make_tuple(d,e,0));
    int mark[a][b] = {};
    while(!q.empty()) {
        // cout<<1;
        auto now = q.front();q.pop();
        int x = get<0>(now);
        int y = get<1>(now);
        int t = get<2>(now);
        t++;
        if(x == f && y == g) {
            cout<<--t;
            return 0;
        }
        for(int k = 0;k<=3;k++) {
            int nx = x + xx[k];
            int ny = y + yy[k];
            if(x >= 0 && x < a && y >= 0 && y < b) {
                if((!c[nx][ny][t / 4])&&(!mark[nx][ny])) {
                    mark[nx][ny] = 1;
                    q.push(make_tuple(nx,ny,t));
                }
            }
        }
    }
    cout<<"impossible";
    return 0;
}
