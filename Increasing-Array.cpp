// Author : ysh
// 08/17/2022 Wed 10:33:50.27
// https://cses.fi/problemset/task/1094/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    int last = 0;
    int ans = 0;
    for(int &i : f) {
        cin>>i;
        if(i < last) {
            ans += last - i;
        } else {
            last = i;
        }
    }
    cout<<ans;
    return 0;
}