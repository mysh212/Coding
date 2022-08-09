// Author : ysh
// 08/09/2022 Tue 15:34:23
// https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
using namespace std;
int xx[] = {1,0,-1,0};
int yy[] = {0,-1,0,1};
char dd[] = {'D','L','U','R'};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int sx,sy,gx,gy;
    bool c[a][b] = {};
    for(int i = 0;i<a;i++) {
        string tmp;cin>>tmp;
        for(int j = 0;j<b;j++) {
            char now = tmp[j];
            if(now == '#') {
                c[i][j] = 1;
            }
            if(now == 'A') {
                sx = i;
                sy = j;
                c[i][j] = 1;
            }
            if(now == 'B') {
                gx = i;
                gy = j;
            }
        }
    }
    // for(int i = 0;i<a;i++) {
    //     for(int j = 0;j<b;j++) {
    //         cout<<(int) c[i][j];
    //     }
    // }
    bool o = 0;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    int mark[a][b] = {};
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.first;
        int y = now.second;
        // cerr<<x<<" "<<y<<"\n";
        if(x == gx && y == gy) {
            o = 1;
            break;
        }
        for(int i =0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < a && nx >= 0 && ny < b && ny >= 0 && (!c[nx][ny])) {
                mark[nx][ny] = i;
                c[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    vector<int>ans;
    // for(int i = 0;i<a;i++) {
    //     for(int j = 0;j<b;j++) {
    //         cout<<dd[mark[i][j]]<<" ";
    //     }
    //     cout<<"\n";
    // }
    while(o) {
        // cerr<<gx<<" "<<gy<<"\n";
        // cerr<<1;
        ans.push_back(mark[gx][gy]);
        int x = gx;
        int y = gy;
        gx = gx - xx[mark[x][y]];
        gy = gy - yy[mark[x][y]];
        if(gx == sx && gy == sy) {
            // ans = dd[mark[gx][gy]] + ans;
            break;
        }
    }
    if(!o) cout<<"NO";
    else {
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        while(!ans.empty()) {
            cout<<dd[ans.back()];ans.pop_back();
        }
    }
    return 0;
}
