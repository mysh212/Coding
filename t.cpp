// Author : ysh
// 03/03/2023 Fri 15:22:19.66
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n,(int) 1e9));
    for(int i = 1;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a][b] = min(c,f[a][b]);
        f[b][a] = min(c,f[b][a]);
    }
    for(int i = 0;i<n;i++) f[i][i] = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            for(int k = 0;k<n;k++) {
                f[j][k] = min(f[j][i] + f[i][k],f[j][k]);
            }
        }
    }
    debug(f);
    int mmax,secmax;mmax = secmax = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(f[i][j] == INT_MAX) continue;
            if(f[i][j] >= mmax) {
                if(f[i][j] == mmax) continue;
                swap(mmax,secmax);
                mmax = f[i][j];
                continue;
            }
            if(f[i][j] > secmax) {
                secmax = f[i][j];
            }
        }
    }
    cout<<secmax;
    return 0;
}