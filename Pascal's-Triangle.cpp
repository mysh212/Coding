// Author : ysh
// 06/05/2022 Sun 21:58:54.94
// https://192.168.193.20/contest/2/problem/023
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f[2];
    int n;cin>>n;
    if(n == 0) return 0;
    f[0].push_back(1);
    cout<<"1\n";
    for(int i = 1;i<n;i++) {
        f[i & 1].clear();
        f[i & 1].push_back(1);
        for(int j = 1;j<i;j++) {
            f[i & 1].push_back(f[!(i & 1)].at(j) + f[!(i & 1)].at(j - 1));
        }
        f[i & 1].push_back(1);
        for(int k = 0;k<i + 1;k++) {
            cout<<f[i & 1].at(k)<<" \n"[k == i];
        }
        // cout<<"\n";
    }
    return 0;
}