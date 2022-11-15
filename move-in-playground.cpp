// Author : ysh
// 11/07/2022 Mon 20:01:04.59
// http://choj.me/problem/d015
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {1,0,-1,0};
const int yy[] = {0,1,0,-1};
struct box{
    int x,y,z,r;
    box(int x = 0,int y = 0,int z = 0,int r = 0):
        x(x), y(y), z(z), r(r) {};
    bool operator<(const box a) const {
        if(z == a.z) return r > a.r;
        return z > a.z;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int rx,ry;cin>>rx>>ry;
    priority_queue<box>q;
    q.push(box(rx,ry));
    cin>>rx>>ry;
    map<pair<int,int>,vector<pair<int,int>>>m;
    int n;cin>>n;
    while(n--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        for(int i = 0;i<=1;i++) {
            if(m.find({a,b}) == m.end()) {
                m.insert({{a,b},vector<pair<int,int>>({{c,d}})});
            } else {
                m.find({a,b})->second.push_back({c,d});
            }
            swap(a,c);
            swap(b,d);
        }
    }
    vector<vector<bool>>mark(a,vector<bool>(b));
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.z;
        int x = now.x;
        int y = now.y;
        int r = now.r;
        if(x == rx && y == ry) {
            cout<<l<<" "<<r;
            return 0;
        }
        if(mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;
        // cout<<x<<" "<<y<<"\n";
        if(m.find({x,y}) != m.end()) {
            for(auto &i : m.find({x,y})->second) {
                q.push(box(i.first,i.second,l,r + 1));
            }
        }
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
            q.push(box(nx,ny,l + 1,r));
        }
    }
    for(auto i : mark) {for(int j : i) cout<<j<<" "; cout<<"\n";}
    return -1;
}