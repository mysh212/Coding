// Author : ysh
// 2023/08/25 Fri 22:03:50
// https://codeforces.com/group/bzV2fc45zy/contest/463655/problem/F
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first;
    }
    for(auto &i : f) {
        cin>>i.second;
    }
    sort(f.begin(),f.end());

    int now = 0;
    for(auto &i : f) {
        now = now + i.second;
        if(i.first - now < 0) return cout<<"No",0;
    }
    cout<<"Yes";
    return 0;
}