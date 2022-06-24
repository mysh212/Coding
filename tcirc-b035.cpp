// Author : ysh
// 06/21/2022 Tue 11:10:24.68
// https://judge.tcirc.tw/ShowProblem?problemid=b035
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    unordered_multiset<int>m;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int ans = 0;
    int r;cin>>r;
    for(int i : f) {
        ans += m.count(r - i);
        m.insert(i);
    }
    cout<<ans;
    return 0;
}