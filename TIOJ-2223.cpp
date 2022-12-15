// Author : ysh
// 12/13/2022 Tue  7:58:35.23
// https://tioj.ck.tp.edu.tw/problems/2223
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    vector<int>f(k + 1);
    vector<pair<int,int>>v(n);
    for(auto &i : v) {
        cin>>i.first>>i.second;
    }
    sort(v.begin(),v.end(),[] (pair<int,int>a,pair<int,int>b) {
        return a.second > b.second;
    });
    int ans = 0;
    for(auto &i : v) {
        if(k - i.first < 0) {
            ans = ans + i.second * k;
            break;
        }
        ans = ans + i.second * i.first;
        k = k - i.first;
    }
    cout<<ans;
    return 0;
}