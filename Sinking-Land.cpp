// Author : ysh
// 2024/08/05 Mon 12:09:28
// https://atcoder.jp/contests/abc363/tasks/abc363_e
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a,vector<int>(b));

    for(auto &i : f) {
        for(int &j : i) {
            cin>>j;
        }
    }

    int ans = 0;
    vector<vector<bool>>mark(a,vector<bool>(b));
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;

    for(int i = 0;i<a;i++) q.push({f.at(i).at(b - 1),i,b - 1}),q.push({f.at(i).at(0),i,0});
    for(int i = 0;i<b;i++) q.push({f.at(a - 1).at(i),a - 1,i}),q.push({f.at(0).at(i),0,i});
    
    // cerr<<1;
    int t = 1;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now[0];
        int x = now[1];
        int y = now[2];

        if(mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;

        while(l > t && t <= c) cout<<(a * b) - ans<<"\n",t++;

        ans++;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if(nx < 0 || nx >= a || ny < 0 || ny >= b) continue;

            q.push({f.at(nx).at(ny),nx,ny});
        }
    }

    while(t <= c) cout<<(a * b) - ans<<"\n",t++;
    return 0;
}