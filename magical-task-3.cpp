// Author : ysh
// 10/29/2022 Sat 13:25:25.64
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y,z;
    box(int x,int y,int z):
        x(x), y(y), z(z) {};
};
int n;
vector<bool>mark;
queue<int>q;
bool ck(int x,vector<vector<int>>&v,vector<int>&now) {
    for(int i : v.at(x)) {
        if(mark.at(i)) continue;
        mark.at(i) = 1;
        q.push(i);
        if(now.at(i) == -1) {
            // mark.at(i) = 1;
            now.at(i) = x;
            return 1;
        }
        if(ck(now.at(i),v,now)) {
            now.at(i) = x;
            return 1;
        }
    }
    return 0;
}
int check(int m,vector<box>&f) {
    vector<int>now(m,-1);
    vector<vector<int>>v(m);
    mark.resize(m);
    int ans = m;
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<m;j++) {
            if(i == j) continue;
            if(abs(f.at(i).x - f.at(j).x) + abs(f.at(i).y - f.at(j).y) <= f.at(j).z - f.at(i).z) v.at(i).push_back(j);
        }
    }
    for(int i = 0;i<m;i++) {
        if(ck(i,v,now)) ans--;
        debug(v);
        while(!q.empty()) mark.at(q.front()) = 0,q.pop();
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<box>f;
        for(int i = 0;i<m;i++) {
            int a,b,c;cin>>a>>b>>c;
            f.push_back(box(b,c,a));
        }
        cout<<check(m,f)<<"\n";
    }
    return 0;
}