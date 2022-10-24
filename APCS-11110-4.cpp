// Author : ysh
// 10/23/2022 Sun 19:15:33.16
#include<bits/stdc++.h>
using namespace std;
bool c = 1;
inline bool check(pair<int,int>&a,int b,int c,pair<int,int>d,bool e = 0) {
    int tmp = max(abs(b - c),d.first);
    if(a.first == tmp) {
        if(a.second > d.second) c = 1,a.second = d.second + 1;
        return 1;
    }
    if(a.first > tmp) {
        a.second = d.second + 1;
        a.first = tmp;
        c = 1;
        return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    vector<vector<pair<int,int>>>mark(n,vector<pair<int,int>>(n,{INT_MAX,0}));
    // vector<vector<int>>f(n,vector<int>(n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>f[i][j];
        }
    }
    mark[0][0].first = 0;
    for(int k = 0;c;k++) {
        c = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) check(mark[i][j],f[i][j],f[i][j - 1],mark[i][j - 1]);
                else if(j == 0) check(mark[i][j],f[i][j],f[i - 1][j],mark[i - 1][j]);
                else check(mark[i][j],f[i][j],f[i - 1][j],mark[i - 1][j],check(mark[i][j],f[i][j],f[i][j - 1],mark[i][j - 1]));
            }
            for(int j = n - 2;j>=0;j--) {
                check(mark[i][j],f[i][j],f[i][j + 1],mark[i][j + 1]);
            }
        }
        for(int i = n - 2;i>=0;i--) {
            for(int j = 0;j<n;j++) {
                check(mark[i][j],f[i][j],f[i + 1][j],mark[i + 1][j]);
            }
        }
    }
    cout<<mark[n - 1][n - 1].first<<"\n"<<mark[n - 1][n - 1].second;
    return 0;
}