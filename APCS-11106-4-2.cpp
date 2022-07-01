// Author : ysh
// 06/14/2022 Tue  8:26:42.81
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(b);
    for(int &i : f) {
        cin>>i;
    }
    for(int &i : g) {
        cin>>i;
    }
    int sig = 0;
    int ans = INT_MIN;
    vector<vector<int>>c(a,vector<int>(b));
    // for(int l = 0;l <= 1;l++) {
        // for(int i = 0;i<a;i++) {
        //     for(int j = 0;j<b;j++) {
        //         c[i][j] = f[i] * g[j];
        //     }
        // }
        // for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                int pi = 0;
                int pj = j;
                sig = 0;
                while(pi != a) {
                    // debug(pi,pj);
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[pj++];
                    ans = max(ans,sig);
                    if(pj == b) {
                        // cerr<<1;
                        pj = 0;
                        sig = 0;
                    }
                }
            }
            for(int j = 0;j<b;j++) {
                int pi = 0;
                int pj = j;
                sig = 0;
                while(pi != a) {
                    // debug(pi,pj);
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[pj--];
                    ans = max(ans,sig);
                    if(pj == -1) {
                        // cerr<<1;
                        pj = b - 1;
                        sig = 0;
                    }
                }
            }
        // }
        // reverse(g.begin(),g.end());
    // }
    cout<<ans;
    return 0;
}