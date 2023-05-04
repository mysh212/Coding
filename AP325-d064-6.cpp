// Author : ysh
// 05/02/2023 Tue 23:39:50.05
// https://judge.tcirc.tw/ShowProblem?problemid=d064
#include<bits/stdc++.h>
using namespace std;
#define int long long
#include<fast>
#include<tree>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    tree<int>t((int) 1e6 + 2);
    int ans = 0;
    for(int i = 0,tmp;i<n;i++) {
        cin>>tmp;
        t.add(tmp,1);
        if(tmp != (int) 1e6) ans = ans + t.sum(tmp + 1,(int) 1e6);
    }
    cout<<ans;
    return 0;
}