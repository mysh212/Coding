// Author : ysh
// 12/13/2022 Tue 10:47:46.25
// NF
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int c;cin>>c;
    vector<vector<int>>f(b);
    for(int i = 0;i<b;i++) {
        int x,y;cin>>x>>y;
        f.at(i).push_back(b + x);
        f.at(i).push_back(y);
    }
    vector<int>now(b + a,-1);
}