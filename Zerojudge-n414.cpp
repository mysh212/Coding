// Author : ysh
// 2024/03/30 Sat 12:21:02
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<vc<int>>f(n,vc<int>(n));
    cin>>f;

    vc<vc<bool>>mark(n,vc<bool>(n));
    vc<vc<int>>ans(n,vc<int>(n));
    queue<pair<int,pair<int,int>>>q;

    re(i,n) re(j,n) if(f.at(i).at(j) == 1) q.push({0,{i,j}});
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int l = now.first;
        int x = now.second.first;
        int y = now.second.second;

        if(mark.at(x).at(y)) continue;
        mark.at(x).at(y) = 1;
        ans.at(x).at(y) = l;
        re(i,4) {
            int nx = x + xx[i];
            int ny = y + yy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || f.at(nx).at(ny) == -1) continue;

            q.push({l + 1,{nx,ny}});
        }
    }
    
    int mmax = 0;
    repo(&i,ans) mmax = max(mmax,*max_element(all(i)));
    out(mmax);
    return 0;
}