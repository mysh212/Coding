// Author : ysh
// 08/27/2022 Sat 21:15:01.46
// https://atcoder.jp/contests/abc266/tasks/abc266_d
#include<bits/stdc++.h>
using namespace std;
inline bool cp(int a,array<int,3> b) {
    return a < b[0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(10,vector<int>(100005));
    vector<vector<int>>l(10,vector<int>(100005));
    for(int i = 0;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        l[b + 2][a + 2] = c;
    }
    // sort(l.begin(),l.end());
    for(int i = 2;i<100005;i++) {
        for(int j = 2;j<=6;j++) {
            f[j][i] = max({f[j][i - 1],f[j - 1][i - 1],f[j + 1][i - 1],f[j - 2][i - 2],f[j + 2][i - 2]}) + l[j][i];
        }
    }
    int mmax = 0;
    for(int i = 2;i<=6;i++) {
        mmax = max(mmax,f[i][100004]);
    }
    cout<<mmax;
    return 0;
}