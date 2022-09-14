// Author : ysh
// 09/10/2022 Sat 14:52:31.14
// https://judge.tcirc.tw/ShowProblem?problemid=d055
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
    sort(f.begin(),f.end(),greater<pair<int,int>>());
    int mmax = 0;
    int x = -1;
    int ans = 0;
    for(auto &i : f) {
        if(i.first == x) continue;
        if(mmax >= i.second) {
            x = i.first;
            continue;
        }
        x = i.first;
        mmax = i.second;
        ans++;
    }
    cout<<ans;
    return 0;
}