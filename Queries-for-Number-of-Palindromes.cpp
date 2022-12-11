// Author : ysh
// 12/09/2022 Fri 14:24:25.70
// https://codeforces.com/contest/245/problem/H
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int n = a.size();
    vector<vector<bool>>g(n,vector<bool>(n));
        for(int j = 0;j<n;j++) {
    for(int i = 0;i<n;i++) {
            if(j == 0) g.at(i).at(i) = 1;
            else {
                int r = i + j;
                if(r >= n) break;
                if(a.at(i) == a.at(r)) {
                    if(j == 1) g.at(i).at(r) = 1;
                    else g.at(i).at(r) = g.at(i + 1).at(r - 1);
                }
            }
        }
    }
    vector<vector<int>>f(n,vector<int>(n));
        for(int k = 0;k < n;k++) {
    for(int i = 0;i<n;i++) {
            int j = i + k;
            if(j >= n) break;
            if(i == j) {
                f.at(i).at(j) = 1;
                continue;
            }
            f.at(i).at(j) = f.at(i + 1).at(j) + f.at(i).at(j - 1) - f.at(i + 1).at(j - 1) + ((int) g.at(i).at(j));
        }
    }
    // for(auto i : f) {for(int j : i) cerr<<j<<" "; cerr<<"\n";}
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        if(a > b) swap(a,b);
        cout<<f.at(a - 1).at(b - 1)<<"\n";
    }
    return 0;
}