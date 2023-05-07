// Author : ysh
// 05/06/2023 Sat 23:14:09.67
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<vector<int>>f(a,vector<int>(b));
        vector<vector<bool>>mark(a,vector<bool>(b));
        for(auto &i : f) {
            for(int &j : i) {
                cin>>j;
            }
        }

        function<int(int,int)> check = [&] (int x,int y) {
            if(f.at(x).at(y) <= 0) return 0;
            if(mark.at(x).at(y)) return 0;
            mark.at(x).at(y) = 1;
            int sig = 0;
            for(int i = 0;i<=3;i++) {
                int nx = x + xx[i];
                int ny = y + yy[i];
                if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                sig = sig + check(nx,ny);
            }
            return sig + f.at(x).at(y);
        };

        int mmax = 0;
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                if(!mark.at(i).at(j)) {
                    mmax = max(mmax,check(i,j));
                }
            }
        }
        cout<<mmax<<"\n";
    }
    return 0;
}