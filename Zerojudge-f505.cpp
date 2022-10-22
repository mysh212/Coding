// Author : ysh
// 10/20/2022 Thu  9:44:27.82
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y,r,z;
    box(int a = 0,int b = 0,int r = 0,int c = 0):
        x(a), y(b), r(r), z(c) {};
    inline bool operator<(const box a) const {
        return z > a.z;
    }
    inline bool operator() (box a,box b) {
        return a.z < b.z;
    }
};
vector<vector<bool>>mark;
priority_queue<box>q;
int found = INT_MIN;
int fillwater = 0;
void check(int a,int b,int d,int c) {
    while(!q.empty()) q.pop();
    q.emplace(0,0,d,0);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        if(mark.at(now.x).at(now.y)) continue;
        mark.at(now.x).at(now.y) = 1;
        int x = now.x;
        int y = now.y;
        int z = now.r;
        int r = now.z;
        debug(x,y,z,r);
        if(x > found && x < c) {
            found = x;
            fillwater = r;
        }
        if(y > found && y < c) {
            found = y;
            fillwater = r;
        }
        if(z > found && z < c) {
            found = z;
            fillwater = r;
        }
        if(x == c || y == c || z == c) {
            cout<<r<<" "<<c<<"\n";
            return;
        }
        int leftfill = min((x + y),a);
        int rightfill = min((x + y),b);
        q.push(box(leftfill,x + y - leftfill,z,r + leftfill - x));
        q.push(box(x + y - rightfill,rightfill,z,r + rightfill - y));
        leftfill = min((z + y),b);
        rightfill = min((z + y),d);
        q.push(box(x,leftfill,(y + z) - leftfill,r + leftfill - y));
        q.push(box(x,(y + z) - rightfill,rightfill,r + rightfill - z));
        leftfill = min((x + z),a);
        rightfill = min((x + z),d);
        q.push(box(leftfill,y,(x + z) - leftfill,r + leftfill - x));
        q.push(box((x + z) - rightfill,y,rightfill,r + rightfill - z));
    }
    cout<<fillwater<<" "<<found<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        int r = max({a,b,c}) + 1;
        mark.clear();
        mark.resize(r,vector<bool>(r));
        found = INT_MIN;fillwater = 0;
        check(a,b,c,d);
    }
}