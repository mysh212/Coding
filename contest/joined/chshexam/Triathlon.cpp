#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>f,g,h;
int n;
int mmin = INT_MAX;
vector<vector<int>>mark;
inline void check() {
    for(int i = 1;i<=n;i++) {
        mark[i][0] = mark[i - 1][0] + f[i];
        mark[i][1] = min(mark[i - 1][1] + g[i],mark[i - 1][0] + g[i]);
        mark[i][2] = min({mark[i - 1][2] + h[i],mark[i - 1][1] + h[i]});
    }
    /*
    for(auto i : mark) {
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    */
    mmin = mark[n][2];
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f.resize(n + 1);
    g.resize(n + 1);
    h.resize(n + 1);
    mark.resize(n + 1,vector<int>(3));
    for(int i = 1;i<=n;i++) {
        cin>>f[i]>>g[i]>>h[i];
    }
    check();
    cout<<mmin;
    return 0;
}
