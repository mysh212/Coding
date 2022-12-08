// Author : ysh
// 12/08/2022 Thu  9:39:23.25
// https://apcsclass.csie.ntnu.edu.tw/ShowProblem?problemid=a137
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define att(a) color.at(a.first).at(a.second)
int a,b;
int fx,fy,gx,gy;
vector<vector<pair<int,int>>>color;
pair<int,int> ff(pair<int,int>a) {
    if(att(a) == make_pair(-1,-1)) return att(a) = a;
    if(att(a) == a) return a;
    return att(a) = ff(att(a));
}
inline void mg(pair<int,int>a,pair<int,int>b) {
    // debug(a,b);
    att(ff(a)) = ff(b);
    return;
}
struct box{
    int x,y,z;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
    inline bool operator<(const box a) const {
        return z > a.z;
    }
};
const int xx[] = {-1,0,1,0};
const int yy[] = {0,-1,0,1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    cin>>fx>>fy>>gx>>gy;
    int r;cin>>r;
    color.resize(a,vector<pair<int,int>>(b,{-1,-1}));
    vector<box>f;
    vector<vector<bool>>v(a,vector<bool>(b));
    for(int i = 0;i<r;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.push_back(box(a,b,c));
    }
    v.at(fx).at(fy) = v.at(gx).at(gy) = 1;
    sort(f.begin(),f.end());
    int last = 0;
    while(!f.empty()) {
        auto now = f.back();f.pop_back();
        last = now.z;
        for(int i = 0;i<=3;i++) {
            int nx = now.x + xx[i];
            int ny = now.y + yy[i];
            if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
            if(v.at(nx).at(ny)) mg({now.x,now.y},{nx,ny});
        }
        v.at(now.x).at(now.y) = 1;
        if(ff({fx,fy}) == ff({gx,gy})) {
            cout<<last;
            return 0;
        }
    }
    // cout<<ck(0,mmax,f);
    return -1;
}