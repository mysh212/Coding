// Author : ysh
// 08/25/2022 Thu 17:23:21.41
// https://cses.fi/problemset/task/1638
#include<bits/stdc++.h>
using namespace std;
const int R = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a;
    b = a;
    vector<vector<bool>>f(a + 1,vector<bool>(b + 1));
    vector<vector<int>>c(a + 1,vector<int>(b + 1));
    for(int i = 0;i<a;i++) {
        string s;cin>>s;
        for(int j = 0,len = s.size();j<len;j++) {
            if(s.at(j) == '*') f[i + 1][j + 1] = 1;
        }
    }
    if(!f[1][1]) c[1][1] = 1;
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=b;j++) {
            if(i == 1 && j == 1) continue;
            if(!f[i][j]) c[i][j] = (c[i - 1][j] + c[i][j - 1]) % R;
        }
    }
    cout<<c[a][b];
    return 0;
}