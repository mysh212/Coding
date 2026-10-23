// Author : ysh
// 2026/09/19 Sat 10:14:26
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> pos(n, vector<int> (n, 0));
    vector<vector<int>> color(n ,vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> pos[i][j];
        }
    }
    for(int i = 0; i < n*n; i++) {
        int row = i / n;
        int col = i % n;
        
    }
}