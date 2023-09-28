// Author : ysh
// 2023/07/20 Thu 08:19:18
// NA (60%)
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#define yes "<(_ _)>\n"
#define no ">_<\n"
#define att(i) (color.at(i.first).at(i.second))
int a,b,c;
struct mgbox{
    vector<vector<bool>>v;
    int a,b;
    const int xx[4] = {-1,0,1,0};
    const int yy[4] = {0,1,0,-1};

    mgbox(vector<vector<bool>>&v):
        v(v), a(v.size()), b(v.at(0).size()) {};

    bool walk(int x,int y) {
        if(y == b - 1) return 1;
        v.at(x).at(y) = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
            if(!v.at(nx).at(ny)) if(walk(nx,ny)) return 1;
        }
        return 0;
    }

    bool check() {
        for(int i = 0;i<a;i++) {
            if(!v.at(i).at(0)) if(walk(i,0)) return 1;
        }
        return 0;
    }
};
bool check(vector<pair<int,int>>&f,int x) {
    vector<vector<bool>>v(a,vector<bool>(b));
    for(int i = 0;i<=x;i++) {
        if(f.at(i) == make_pair(-1,-1)) continue;
        v.at(f.at(i).first).at(f.at(i).second) = 1;
    }
    mgbox g(v);
    return g.check();
}
int ck(vector<pair<int,int>>&pre,int l,int r) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(pre,mid)) return ck(pre,mid,r);
    else return ck(pre,l,mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    vector<vector<bool>>f(a,vector<bool>(b));
    vector<pair<int,int>>pre(c);
    for(auto &i : pre) {
        cin>>i.first>>i.second;
        f.at(i.first).at(i.second) = 1;
    }

    int now = ck(pre,-1,c);
    while(now != c - 1) {
        pre.at(now + 1) = {-1,-1};
        now = ck(pre,now + 1,c);
    }

    for(auto &i : pre) {
        if(i == make_pair(-1,-1)) cout<<no;
        else cout<<yes;
    }
    return 0;
}