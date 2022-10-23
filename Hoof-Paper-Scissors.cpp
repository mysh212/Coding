// Author : ysh
// 10/22/2022 Sat 17:14:51.38
// http://www.usaco.org/index.php?page=viewproblem2
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define freopen(...) '*'
#endif

#define H 0
#define P 1
#define S 2
int f[2][21][3] = {};
inline bool win(int a,int b) {
    if(b == a + 1) {
        return 1;
    }
    if(a == 2 && b == 0) {
        return 1;
    }
    return 0;
}
int main() {
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
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
    int wwin = (v.at(0) == 2 ? 0 : v.at(0) + 1);
    // cerr<<wwin;
    for(int i = 0;i<=b;i++) f[0][i][wwin] = 1;
    for(int i = 1;i<a;i++) {
        bool p = i & 1;
        for(int j = 0;j<=b;j++) {
            f[p][j][0] = f[!(p)][j][0] + win(v.at(i),0);
            f[p][j][1] = f[!(p)][j][1] + win(v.at(i),1);
            f[p][j][2] = f[!(p)][j][2] + win(v.at(i),2);
            if(j == 0) continue;
            int mmax = max({f[!(p)][j - 1][0],f[!(p)][j - 1][1],f[!(p)][j - 1][2]});
            f[p][j][0] = max(f[p][j][0],mmax + win(v.at(i),0));
            f[p][j][1] = max(f[p][j][1],mmax + win(v.at(i),1));
            f[p][j][2] = max(f[p][j][2],mmax + win(v.at(i),2));
            // cerr<<f[p][j][0]<<" "<<f[p][j][1]<<" "<<f[p][j][2]<<"\n";
        }
    }
    int ans = 0;
    // for(int i = 0;i<=b;i++) {
        for(int r = 0;r<=2;r++) {
            ans = max(ans,f[(a - 1) & 1][b][r]);
        }
    // }
    cout<<ans;
    return 0;
}