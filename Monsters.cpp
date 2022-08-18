// Author : ysh
// 08/16/2022 Tue  8:08:02.33
// https://cses.fi/problemset/task/1194
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int xx[] = {1,0,-1,0};
const int yy[] = {0,-1,0,1};
const char dd[] = {'D','L','U','R'};
int a,b;
struct box{
    int x,y,z;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
};
void flood(vector<vector<bool>>&f,queue<pair<int,int>>&q,queue<pair<int,int>>&p) {
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.first;
        int y = now.second;
        f[x][y] = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < a && nx >= 0 && ny < b && ny >= 0 && (not f[nx][ny])) {
                f[nx][ny] = 1;
                p.emplace(nx,ny);
            }
        }
        // for(auto i : f) {
        //     for(bool j : i) {
        //         cout<<(j ? 1 : 0);
        //     }
        //     cout<<"\n";
        // }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<vector<bool>>f(a,vector<bool>(b));
    queue<pair<int,int>>qs[2];
    int x,y;
    vector<vector<int>>mark(a,vector<int>(b));
    for(int i = 0;i<a;i++) {
        string a;cin>>a;
        for(int j = 0;j<b;j++) {
            if(a.at(j) == '#') {
                f[i][j] = 1;
            }
            if(a.at(j) == 'M') {
                qs[0].emplace(i,j);
                f[i][j] = 1;
            }
            if(a.at(j) == 'A') {
                x = i;y = j;
            }
        }
    }
    queue<box>p;
    p.emplace(x,y,1);
    int last = 0;
    bool c = 0;
    int nx,ny;
    while(!p.empty()) {
        auto now = p.front();p.pop();
        int x = now.x;
        int y = now.y;
        int t = now.z;
        debug(x,y,t);
        if(x == a - 1 || y == b - 1 || x == 0 || y == 0) {
            nx = x;ny = y;
            c = 1;
            break;
        }
        if(t != last) {
            // for(auto i : f) {
            //     for(bool j : i) {
            //         cerr<<(j ? 1 : 0);
            //     }
            //     cerr<<"\n";
            // }
            last = t;
            flood(f,qs[!(t & 1)],qs[t & 1]);
        }
        f[x][y] = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < a && nx >= 0 && ny < b && ny >= 0 && (not f[nx][ny])) {
                mark[nx][ny] = i;
                p.emplace(nx,ny,t + 1);
            }
        }
    }
    if(c) {
        cout<<"YES"<<"\n";
        // int nx,ny;
        vector<int>v;
        while(nx != x || ny != y) {
        // cerr<<1;
            int x = nx,y = ny;
            nx = x - xx[mark[x][y]];
            ny = y - yy[mark[x][y]];
            v.push_back(mark[x][y]);
        }
        cout<<v.size()<<"\n";
        while(!v.empty()) {
            int now = v.back();v.pop_back();
            cout<<dd[now];
        }
        return 0;
    }
    cout<<"NO";
    return 0;
}