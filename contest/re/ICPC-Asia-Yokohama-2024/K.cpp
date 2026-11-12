// Author : ysh
// 2026/11/05 Thu 15:57:40
#include<bits/stdc++.h>
#include <slow>
using namespace std;
static constexpr int MAXN = 2e5+5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    bool mark[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            mark[i][j] = c == 'Y';
        }
    }

    // vector<bitset<MAXN>> f(25);
    vector<vector<bool>> f(25, vector<bool> (MAXN, 0));

    for(int i = 0; i < m; i++) {
        // f[i].reset();
        for(int j = 0; j < n; j++) {
            f[i][j] = mark[j][i];
        }
    }
    
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cerr << f[i][j] << " \n"[j==n-1];
    //     }
    // }

    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            // auto tmp = f[i] & f[j];
            vector<bool> tmp(MAXN, 0);
            bool check = 1;
            for(int k = 0; k < n; k++) {
                tmp[i] = f[i][k] | f[j][k];
                if(tmp[i] == 0) check = 0;
                // debug(tmp[i]);
                // cout << tmp[i] << " \n"[k+1==n];
            }
            if(check) return cout << i+1 << ' ' << j+1 << '\n', 0;
        }
    }
    cout << "No\n";
}