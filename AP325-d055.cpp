// Author : ysh
// 08/03/2022 Wed 10:06:43
// https://judge.tcirc.tw/ShowProblem?problemid=d055
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i].first;
    }
    for(int i = 0;i<n;i++) {
        cin>>f[i].second;
    }
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });
    int mmax = 0;
    int ans = 0;
    for(auto i : f) {
        if(i.second > mmax) {
            mmax = i.second;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
