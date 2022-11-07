// Author : ysh
// 10/31/2022 Mon 22:50:19.24
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y,z;
    box(int l,int x,int y):
        z(l), x(x), y(y) {};
    inline bool operator<(const box a) const {
        return z > a.z;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    int t = 0;
    while(cin>>a>>b) {
        cout<<"Case #"<<++t<<" :\n";
        vector<vector<int>>f(a,vector<int>(b));
        for(auto &i : f) for(int &j : i) cin>>j;
        priority_queue<box>q;
        q.push({0,0,0});
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.z;
            int x = now.x;
            int y = now.y;
            if(x == a - 1 && y == b - 1) {
                cout<<l<<"\n";
                break;
            }
            if(x + 1 < a) q.push({l + f[x + 1][y],x + 1,y});
            if(y + 1 < b) q.push({l + f[x][y + 1],x,y + 1});
        }
    }
    return 0;
}