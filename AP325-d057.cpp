// Author : ysh
// 07/24/2022 Sun 15:30:58.67
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
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        // if(a.second != b.second) 
        return a.first < b.first;
        // return a.first < b.first;
    });
    int now = 0;
    long long ans = 0;
    for(pair<int,int> i : f) {
        now = now + i.first;
        ans = ans + (i.second - now);
    }
    cout<<ans;
    return 0;
}