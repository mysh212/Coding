// Author : ysh
// 09/30/2022 Fri 14:34:40.20
// https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    sort(f.begin(),f.end());
    function<int(int,int)> check = [&] (int now,int t) {
        int r = now;
        while(r < n) {
            if(f.at(r++).first > t) {
                r--;
                break;
            }
        }
        return r - now;
    };
    int l = 0;int r = 0;
    int now = f.at(0).first;int mmax = 0;
    for(int i = 0;i<n;i++) {
        check(i,f.at(i).second);
    }
}