// Author : ysh
// 08/12/2022 Fri 14:04:58.28
// NF
#include<bits/stdc++.h>
using namespace std;
// char to[] = {R,Y,B,O,P,G,D};
int xx[] = {1,0,-1,0,1,1,-1,-1};
int yy[] = {0,-1,0,1,1,-1,-1,1};
#define R 0
#define Y 1
#define B 2
#define O 3
#define P 4
#define G 5
#define D 6
#define W 7
int c[8];
int mmax[8];
int n;
inline bool ok(int a,int b) {
    return (a < n && a >= 0 && b >= 0 && b < n);
}
inline int mix(int l,int r) {
    if(l > r) swap(l,r);
    bitset<3>b;
    b.reset();
    if(l == R||r == R) {
        b.set(R);
    }
    if(l == Y||r == Y) {
        b.set(Y);
    }
    if(l == B||r == B) {
        b.set(B);
    }
    if(l == O||r == O) {
        b.set(R);
        b.set(Y);
    }
    if(l == G||r == G) {
        b.set(B);
        b.set(Y);
    }
    if(l == P||r == P) {
        b.set(R);
        b.set(B);
    }
    if(l == D||r == D) {
        return D;
    }
    if(b.test(R)) {
        if(b.test(Y)) {
            if(b.test(B)) {
                return D;
            }
            return O;
        }
        return R;
    }
    if(b.test(Y)) {
        if(b.test(B)) {
            return G;
        }
        return Y;
    }
    if(b.test(B)) {
        return B;
    }
    return W;
}
int check(int x,int y,vector<vector<int>> &f) {
    class box{
        public:
        int x,y,z,r;
        box(int x,int y,int z):
            x(x), y(y), z(z) {};
    };
    queue<box>q;
    
    q.push(box(x,y,0));
    int last = 0;
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.x;
        int y = now.y;
        int t = now.z;
        t++;
        for(int i = 0;i<=7;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            int cc = f[x][y];
            if(!ok(nx,ny)) {
                continue;
            }
            int nc = mix(f[x][y],f[nx][ny]);
            if(cc == nc) continue;
            c[f[x][y]]--;
            f[nx][ny] = nc;
            c[nc]++;
            mmax[nc] = max(mmax[nc],c[nc]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
}