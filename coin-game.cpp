// Author : ysh
// 07/01/2022 Fri  6:42:48.34
// https://choj.me/problem/c006
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m,n;cin>>m>>n;
    vector<vector<int>>f(m,vector<int>(m));
    if(n == 0) return 0;
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<m;j++) {
            cin>>f[i][j];
        }
    }
    set<int>g;
    int a,b;cin>>a>>b;
    a = a - 1;
    for(int i = 0;i<m;i++) {
        if(f[a][i] == b) g.insert(i);
    }
    for(int j = 1;j<n;j++) {
        cin>>a>>b;
        a = a - 1;
        for(int i = 0;i<m;i++) {
            if(f[a][i] != b) g.erase(i);
        }
    }
    for(int i : g) {
        cout<<i + 1<<" ";
    }
    return 0;
}