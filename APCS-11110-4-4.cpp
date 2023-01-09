// Author : ysh
// 01/08/2023 Sun 10:11:17.46
// WA
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    for(auto &i : f) {
        for(int &j : i) {
            cin>>j;
        }
    }
    vector<vector<bool>>mark(n,vector<bool>(n));
    priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>q;
    q.push({{0,0},{0,0}});
    int mmin,ans;mmin = ans = INT_MAX;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int h = now.first.first;
        int l = now.first.second;
        int x = now.second.first;
        int y = now.second.second;
        if(x == n - 1 && y == n - 1) {
            if(mmin == INT_MAX) mmin = h;
            if(mmin == h) {
                ans = min(l,ans);
                continue;
            }
            // break;
        }
        if(mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
            if(mark.at(nx).at(ny)) continue;
            q.push({{max(h,abs(f.at(nx).at(ny) - f.at(x).at(y))),l + 1},{nx,ny}});
        }
    }
    cout<<mmin<<"\n"<<ans;
    return 0;
}