// Author : ysh
// 03/02/2023 Thu 17:15:43.31
// https://cses.fi/problemset/task/1660
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int last = 0;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }

    multiset<int>s({0});
    int ans = 0;
    for(int &i : f) {
        auto found = s.count(i - b);
        ans = ans + found;
        s.insert(i);
    }
    cout<<ans;
    return 0;
}