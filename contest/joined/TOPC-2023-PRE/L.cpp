// Author : ysh
// 2023/09/16 Sat 09:42:27
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    for(int i = 0;i<n;i++) {
        cin>>f.at(i)>>g.at(i);
    }
    sort(f.begin(),f.end());
    sort(g.begin(),g.end());

    cout<<f.at((n - 1) >> 1)<<" "<<g.at((n - 1) >> 1);
    return 0;
}