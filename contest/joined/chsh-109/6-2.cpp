// Author : ysh
// 11/06/2022 Sun 16:43:21.14
#include<bits/stdc++.h>
using namespace std;
inline int dt(int a,int b,int c,int d) {
    int aa = (a - b);
    int bb = (c - d);
    return aa * aa + bb * bb;
}
const int xx[] = {1,0,-1,0};
const int yy[] = {0,1,0,-1};
void check(vector<vector<bool>>&f,int x,int y,int m) {
    queue<pair<int,int>>q;
    q.emplace(x,y);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.first;
        int y = now.second;
        if(f[x][y]) continue;
        f[x][y] = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny >= 1000 || ny < 0 || nx >= 1000) {
                // cerr<<nx<<" "<<ny<<"\n";
                continue;
            }
            q.emplace(nx,ny);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<vector<bool>>f(1001,vector<bool>(1001));
        vector<pair<pair<int,int>,int>>v;
        for(int i = 0;i<m;i++) {
            int a,b,c;cin>>a>>b>>c;
            v.push_back({{a,b},c});
        }
        for(int i = 0;i<1000;i++) {
            for(int j = 0;j<1000;j++) {
                for(int k = 0;k<m;k++) {
                    if(dt(v.at(k).first.first,i,v.at(k).first.second,j) <= v.at(k).second * v.at(k).second) {
                        f[i][j] = 1;
                        continue;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<1000;i++) {
            for(int j = 0;j<1000;j++) {
                if(!f[i][j]) {
                    check(f,i,j,m);
                    ans++;
        // for(int i = 0;i<10;i++) {
        //     for(int j = 0;j<10;j++) {
        //         cout<<f[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // system("pause");
                }
            }
        }
        cout<<ans - 1<<"\n";
    }
    return 0;
}