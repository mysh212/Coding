// Author : ysh
// 2023/07/07 Fri 14:33:23
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 1;i<=b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    int ans = 0;
    queue<pair<int,int>>q;
    q.push({0,0});
}