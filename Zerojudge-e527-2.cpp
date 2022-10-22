// Author : ysh
// 10/20/2022 Thu  9:26:16.34
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y,z;
    box(int a = 0,int b = 0,int c = 0):
        x(a), y(b), z(c) {};
    inline bool operator<(const box a) const {
        return z > a.z;
    }
    inline bool operator() (box a,box b) {
        return a.z < b.z;
    }
};
vector<vector<bool>>mark;
priority_queue<box>q;
void check(int a,int b,int c) {
    while(!q.empty()) q.pop();
    q.emplace(0,0,-1);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        if(mark.at(now.x).at(now.y)) continue;
        mark.at(now.x).at(now.y) = 1;
        int x = now.x;
        int y = now.y;
        int r = now.z + 1;
        if(x == c || y == c) {
            cout<<r<<"\n";
            return;
        }
        int leftfill = min((x + y),a);
        int rightfill = min((x + y),b);
        q.push(box(leftfill,x + y - leftfill,r));
        q.push(box(x + y - rightfill,rightfill,r));
        q.push(box(x,0,r));
        q.push(box(0,y,r));
        q.push(box(x,b,r));
        q.push(box(a,y,r));
    }
    cout<<-1<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        int r = max(a,b) + 1;
        mark.clear();
        mark.resize(r,vector<bool>(r));
        check(a,b,c);
    }
}