// Author : ysh
// 11/29/2022 Tue 16:56:30.75
// https://cses.fi/problemset/task/1652
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a + 1,vector<int>(a + 1));
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=a;j++) {
            char tmp;cin>>tmp;
            if(tmp == '*') f.at(i).at(j) = 1;
        }
    }
    // for(int i = 1;i<a;i++) f.at(i).at(0) = f.at(i).at(0) + f.at(i - 1).at(0);
    // for(int i = 1;i<b;i++) f.at(0).at(i) = f.at(0).at(i) + f.at(0).at(i - 1);
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=a;j++) {
            f.at(i).at(j) = f.at(i).at(j) + f.at(i - 1).at(j) + f.at(i).at(j - 1) - f.at(i - 1).at(j - 1);
        }
    }
    while(b--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        cout<<f.at(c).at(d) + f.at(a - 1).at(b - 1) - f.at(a - 1).at(d) - f.at(c).at(b - 1)<<"\n";
    }
    return 0;
}