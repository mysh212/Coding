// Author : ysh
// 02/23/2023 Thu 14:24:53.42
// https://cses.fi/problemset/task/1653
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;
    sort(f.rbegin(),f.rend());
    vector<int>v;
    for(int &i : f) {
        bool c = 0;
        for(int j = 0,len = v.size();j<len;j++) {
            if(v.at(j) + i <= b) {
                v.at(j) = v.at(j) + i;
                c = 1;
                break;
            }
        }
        if(c) continue;
        v.push_back(i);
    }
    cout<<v.size();
    return 0;
}