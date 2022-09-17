// Author : ysh
// 09/15/2022 Thu 21:13:55.25
// https://atcoder.jp/contests/dp/tasks/dp_r
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int R = 1e9 + 7;
#include<square>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,r;cin>>n>>r;
    t<int> tt(0);
    tt.mod(R);
    tt.input(n);
    tt = tt ^ r;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            ans = ans + tt.f.at(i).at(j);
            ans = ans % R;
        }
    }
    cout<<ans;
    return 0;
}