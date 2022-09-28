#include<bits/stdc++.h>
using namespace std;
int a,b;
int ax[] = {0,0,0,1,1,1,-1,-1,-1};
int ay[] = {1,0,-1,1,0,-1,1,0,-1};
int bx[] = {0,1,1,-1,-1};
int by[] = {0,1,-1,1,-1};
int xx[] = {0,0,-1,1};
int yy[] = {1,-1,0,0};
vector<vector<bool>>f;
vector<vector<bool>>mark;
#define int long long
int ck(int,int);
void check();
// void check() {
//     mark.clear();
//     mark.resize(a,vector<bool>(b));
//     int sig = 0;
//     for(int i = 0;i<a;i++) {
//         for(int j = 0;j<b;j++) {
//             if((!f.at(i).at(j)) || mark.at(i).at(j)) continue;
//             sig += ck(i,j);
//             /*
//             for(auto i : mark) {
//                 for(int j : i) {
//                     cout<<j<<" ";
//                 }
//                 cout<<"\n";
//             }
//             */
//         }
//     }
//     cout<<sig<<"\n";
//     return;
// }
// int ck(int x,int y) {
//     if((!f.at(x).at(y)) || mark.at(x).at(y)) return 0;
//     mark.at(x).at(y) = 1;
//     for(int i = 0;i<=3;i++) {
//         int nx = x + xx[i];
//         int ny = y + yy[i];
//         if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
//         ck(nx,ny);
//     }
//     return 1;
// }
#define encode(a,b) 1e3 * a + b
vector<vector<pair<int,int>>>v;
int t = 0;
inline pair<int,int> ff(pair<int,int>r) {
    // cerr<<r.first<<" "<<r.second<<"\n";
    int a = r.first;
    int b = r.second;
    if(v.at(a).at(b) == make_pair(-1LL,-1LL)) {
        t++;
        return v.at(a).at(b) = r;
    }
    if(v.at(a).at(b) == r) return r;
    return v.at(a).at(b) = ff(v.at(a).at(b));
}
inline void mg(pair<int,int>a,pair<int,int>b) {
    auto aa = ff(a);
    auto bb = ff(b);
    if(aa != bb) {
        t--;
        v.at(aa.first).at(aa.second) = v.at(bb.first).at(bb.second);
    }
    return;
}
inline void bomb(int x,int y) {
    for(int i = 0;i<=3;i++) {
        int nx = x + xx[i];
        int ny = y + yy[i];
        if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
        if(f.at(nx).at(ny)) mg({nx,ny},{x,y});
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a,vector<bool>(b));
    v.resize(a,vector<pair<int,int>>(b,{-1,-1}));
    int m;cin>>m;
    for(int i = 0;i<m;i++) {
        char tmp;cin>>tmp;
        int x,y;cin>>x>>y;
        x--,y--;
        if(tmp == 'A') for(int i = 0;i<=8;i++) {
            int nx = x + ax[i];
            int ny = y + ay[i];
            if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
            ff({nx,ny});
            f.at(nx).at(ny) = 1;
            bomb(nx,ny);
        }
        if(tmp == 'B') for(int i = 0;i<=4;i++) {
            int nx = x + bx[i];
            int ny = y + by[i];
            if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
            ff({nx,ny});
            f.at(nx).at(ny) = 1;
            bomb(nx,ny);
        }
        cout<<t<<"\n";
        // for(auto i : v) {
        //     for(pair<int,int> j : i) {
        //         printf("{%d,%d} ",j.first,j.second);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}
