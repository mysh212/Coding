// Author : ysh
// 10/22/2022 Sat 17:14:51.38
// http://www.usaco.org/index.php?page=viewproblem2
#include<bits/stdc++.h>
using namespace std;
#define H 0
#define P 1
#define S 2
int f[2][20][3] = {};
inline bool win(int a,int b) {
    if(b == a + 1) {
        return 1;
    }
    if(a == 0 && b == 2) {
        return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>v(a);
    for(int i = 0;i<a;i++) {
        char tmp;cin>>tmp;
        if(tmp == 'H') v.at(i) = H;
        if(tmp == 'P') v.at(i) = P;
        if(tmp == 'S') v.at(i) = S;
    }
    int wwin = (v.at(0) - 1 == -1 ? v.at(0) - 1 : 2);
    f[0][0][wwin] = 1;
    for(int i = 1;i<a;i++) {
        for(int j = 0;j<=b;j++) {
            for(int k = 0;k<=2;k++) {
                f[i & 1][j][k] = max(f[i & 1][j][k],f[!(i & 1)][j][k] + win(v.at(i),k));
                for(int r = 0;r<=2;r++) {
                    f[i & 1][j][k] = max(f[i & 1][j][k],f[!(i & 1)][j - 1][r] + win(v.at(i),r));
                }
                cerr<<f[i & 1][j][k]<<" ";
            }
            cerr<<"\n";
        }
    }
    int ans = 0;
    for(int i = 0;i<=b;i++) {
        for(int r = 0;r<=2;r++) {
            ans = max(ans,f[(a - 1) & 1][i][r]);
        }
    }
    cout<<ans;
    return 0;
}