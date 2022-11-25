// Author : ysh
// 11/25/2022 Fri  8:30:19.70
// https://codeforces.com/problemset/problem/837/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int c[201][202][102] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    int mmax = 0;
    for(auto &i : f) {
        int tmp;cin>>tmp;
        if(tmp == 0) continue;
        while(!(tmp & 1) && tmp != 0) {
            tmp = tmp >> 1;
            i.first++;
        }
        while(tmp % 5 == 0 && tmp != 0) {
            tmp = tmp / 5;
            i.second++;
        }
        mmax = max(i.second,mmax);
    }
    debug(f);
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            for(int k = 0;k<mmax;k++) {
                if(k + f.at(i).second >= f.at(i).first) c[i + 1][j + 1][k + f.at(i).second] = max(c[i + 1][j + 1][k + f.at(i).second],c[i][j][k] + f.at(i).first);
                c[i + 1][j][k] = max(c[i + 1][j][k],c[i][j][k]);
            }
        }
    }
    for(int i = 0;i<=a;i++) {
        for(int j = 0;j<=b;j++) {
            for(int k = 0;j<=mmax;k++) {
                cerr<<c[i][j][k]<<" ";
            }
            cerr<<"\n";
        }
        cerr<<"\n";
    }
    cout<<c[a][b][mmax];
    return 0;
}
