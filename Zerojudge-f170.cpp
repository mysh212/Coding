// Author : ysh
// 08/12/2022 Fri 13:37:11.06
#include<bits/stdc++.h>
using namespace std;
#define int long long
int xx[] = {1,0,-1,0};
int yy[] = {0,-1,0,1};
vector<vector<int>>f;
vector<vector<bool>>mark;
int n;
int ans = 0;
inline bool ok(int a,int b,int r) {
    return (a < n && a >= 0 && b >= 0 && b < n && (!mark[a][b]) && (abs(f[a][b] - r) <= 2));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    class box{
        public:
        void find(int x,int y) {
            queue<pair<int,int>>q;
            q.push({x,y});
            mark[x][y] = 1;
            while(!q.empty()) {
                auto now = q.front();q.pop();
                int x = now.first;
                int y = now.second;
                // cerr<<x<<" "<<y<<"\n";
                ans++;
                for(int i = 0;i<=3;i++) {
                    int nx = x + xx[i];
                    int ny = y + yy[i];
                    if(!ok(nx,ny,f[x][y])) continue;
                    mark[nx][ny] = 1;
                    q.emplace(nx,ny);
                }
            }
            return;
        }
        void operator() (int x,int y) {
            find(x,y);
        }
    }check;
    cin>>n;
    int a,b;cin>>a>>b;
    f.resize(n,vector<int>(n));
    mark.resize(n,vector<bool>(n));
    for(auto &i : f) {
        for(int &j : i) {
            cin>>j;
        }
    }
    check(a,b);
    cout<<ans;
    return 0;
}