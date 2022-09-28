// Author : ysh
// 09/25/2022 Sun  8:46:07.97
// https://codeforces.com/contest/1734/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<int>f(m);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        int mmin = LONG_LONG_MAX;
        for(int i = 1;i + 1<m;i++) {
            mmin = min(f[i + 1] - f[i - 1],mmin);
        }
        // mmin = min({mmin,(f[m - 1] << 1) - f[m - 2] - f[m - 3],abs(f[m - 2] - f[m - 1]) + abs(f[m - 2] - f[m - 3])});
        cout<<mmin<<"\n";
    }
    return 0;
}