// Author : ysh
// 08/05/2022 Fri 12:49:18.25
#include<bits/stdc++.h>
using namespace std;
int xx[] = {1,0,-1,0};
int yy[] = {0,-1,0,1};
inline void pc(vector<vector<bool>> &f) {
    for(auto i : f) {
        for(bool j : i) {
            cout<<(j ? "1" : "0");
        }
        cout<<"\n";
    }
    return;
}
struct box{
    int x,y,r,l;
    box(int a,int b,int c = 0,int d = 0) {
        x = a;
        y = b;
        r = c;
        l = d;
    }
    inline int first() {
        return x;
    }
    inline int second() {
        return y;
    }
    inline int t() {
        return r;
    }
    inline int lt() {
        return r;
    }
    bool operator<(box a) {
        return r < a.r;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<box>q;
    int a,b;cin>>a>>b;
    vector<vector<bool>>f(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        string a;cin>>a;
        for(int j = 0;j<b;j++) {
            if(a.at(j) == '1') {
                f.at(i).at(j) = 1;
            }
        }
    }
    q.push(box(0,0));
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int x = now.first();
        int y = now.second();
        int r = now.t();
        if(x == a - 1 && y == b - 1) {
            cout<<r;
            return 0;
        }
        int lt = now.lt();
        f[x][y] = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || nx >= a || ny < 0 || ny >= b || f[nx][ny]) continue;
            if(lt != i) {
                cout<<x<<" "<<y<<"\n";
                cout<<i<<" "<<lt<<"\n";
                pc(f);
            }
            if(x != 0 || y != 0) q.push(box(nx,ny,r + (lt == i ? 0 : 1),i));
            else q.push(box(nx,ny,0,i));
        }
    }
    cout<<"-1";
    return 0;
}