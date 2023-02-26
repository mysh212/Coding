// Author : ysh
// 02/26/2023 Sun 18:26:33.16
// https://judge.tcirc.tw/ShowProblem?problemid=d093
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y,l,last;
    box(int x = 0,int y = 0,int l = 0,int last = 0):
        x(x), y(y), l(l), last(last) {};
    bool operator<(const box &a) const {
        return l > a.l;
    }
};
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<bool>>f(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            char tmp;cin>>tmp;
            while(!(tmp == '0' || tmp == '1')) cin>>tmp;
            f.at(i).at(j) = (tmp == '1');
        }
    }
    if(a == 1 && b == 1 && !f.at(0).at(0)) {
        cout<<"0";
        return 0;
    }

    // for(int i = 0;i<a;i++) {
    //     for(int j = 0;j<b;j++) {
    //         cerr<<(int) f.at(i).at(j)<<" ";
    //     }
    //     cerr<<"\n";
    // }
    vector<vector<vector<bool>>>mark(4,vector<vector<bool>>(a,vector<bool>(b)));
    priority_queue<box>q;
    q.push(box(0,0,0,-1));
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int x = now.x;
        int y = now.y;
        int l = now.l;
        int last = now.last;
        if(mark.at(max(last,0)).at(x).at(y) || f.at(x).at(y)) continue;
        mark.at(max(last,0)).at(x).at(y) = 1;
        if(x == a - 1 && y == b - 1) {
            cout<<l - 1;
            return 0;
        }
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
            q.push(box(nx,ny,l + (i == last ? 0 : 1),i));
        }
    }
    cout<<"-1";
    return 0;
}