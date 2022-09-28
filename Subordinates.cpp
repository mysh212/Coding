// Author : ysh
// 09/21/2022 Wed 15:41:09.20
// https://cses.fi/problemset/task/1674
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>f;
vector<int>ans;
int check(int x) {
    for(int &i : f.at(x)) {
        ans.at(x) += check(i);
    }
    return ans.at(x) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    ans.resize(n);
    for(int i = 1;i<n;i++) {
        int tmp;cin>>tmp;
        f.at(--tmp).push_back(i);
    }
    check(0);
    for(int &i : ans) {
        cout<<i<<" ";
    }
    return 0;
}