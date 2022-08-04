// Author : ysh
// 07/31/2022 Sun 17:01:02.71
// https://cses.fi/problemset/task/1660
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int last = 0;
    int ans = 0;
    map<int,int>m({{0,1}});
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        tmp = last += tmp;
        auto found = m.find(tmp - b);
        if(found != m.end()) {
            ans = ans + found->second;
        }
        m[tmp]++;
    }
    cout<<ans;
    return 0;
}