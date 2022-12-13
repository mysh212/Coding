// Author : ysh
// 12/13/2022 Tue  8:46:44.23
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int,int>>f;
    int n,k;cin>>n>>k;
    vector<int>v(k + 1);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        return a.second > b.second;
    });
}