// Author : ysh
// 06/12/2022 Sun 11:08:08.42
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>grid{{5,3},{4,0},{2,1}};
    vector<vector<int>>moveCost{{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>f(n,vector<int>(m));
        for(int i = 0;i<m;i++) {
            f[0][i] = grid[0][i];
        }
        for(int i = 1;i<n;i++) {
            for(int j = 0;j<m;j++) {
                int mmin = INT_MAX;
                for(int k = 0;k<m;k++) {
                    int tmp = grid[i - 1][k];
                    mmin = min(mmin,moveCost[tmp][j] + f[i - 1][k] + grid[i][j]);
                }
                f[i][j] = mmin;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<m;i++) {
            ans = min(ans,f[n - 1][i]);
        }
        return ans;
}