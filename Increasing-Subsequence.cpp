// Author : ysh
// 08/19/2022 Fri 19:22:20.07
// https://cses.fi/problemset/task/1145
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>v;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        auto found = lower_bound(v.begin(),v.end(),tmp);
        if(found != v.end()) *found = tmp;
        else v.push_back(tmp);
    }
    cout<<v.size();
    return 0;
}