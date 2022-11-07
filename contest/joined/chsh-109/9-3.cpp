// Author : ysh
// 11/06/2022 Sun 11:32:59.06
#include<bits/stdc++.h>
using namespace std;
// #define int long long
int a,b;
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
inline int encoding(int x,int y) {
    return x * b + y;
}
struct box{
    int x,y,z,r;
    box(int x = 0,int y = 0,int z = 0,int r = 0):
        x(x), y(y), z(z), r(r) {};
    inline bool operator<(const box a) const {
        if(z == a.z) return r > a.r;
        return z > a.z;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    // for(int i = 0;i<5;i++) {
    //     for(int j = 0;j<7;j++) {
    //         cerr<<encoding(i,j)<<" ";
    //     }
    //     cerr<<"\n";
    // }
    vector<vector<pair<int,int>>>m(a * b);
    int x,y,rx,ry;cin>>x>>y>>rx>>ry;
    int n;cin>>n;
    while(n--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        m.at(encoding(a,b)).push_back({c,d});
    }
    queue<box>q[2];
    vector<vector<bool>>mark(a,vector<bool>(b));
    q[0].push(box(x,y,0,0));
    int now = 0;
    while(1) {
        int mmin = INT_MAX;
        int t = now & 1;
        while(!q[t].empty()) {
            auto now = q[t].front();q[t].pop();
            int l = now.z;
            int x = now.x;
            int y = now.y;
            int r = now.r;
            if(x == rx && y == ry) {
                mmin = min(r,mmin);
                // return 0;
            }
            if(mark.at(x).at(y)) continue;
            mark.at(x).at(y) = 1;
            if(!m.at(encoding(x,y)).empty()) {
                for(pair<int,int> &i : m.at(encoding(x,y))) {
                    int x = i.first;
                    int y = i.second;
                    for(int i = 0;i<=3;i++) {
                        int nx = x + xx[i];
                        int ny = y + yy[i];
                        if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
                        q[!t].push(box(nx,ny,l + 1,r + 1));
                    }
                }
            }
            for(int i = 0;i<=3;i++) {
                int nx = x + xx[i];
                int ny = y + yy[i];
                if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
                q[!t].push(box(nx,ny,l + 1,r));
            }
        }
        if(mmin != INT_MAX) {
            cout<<now<<" "<<mmin;
            return 0;
        }
        now++;
    }
    return -1;
}