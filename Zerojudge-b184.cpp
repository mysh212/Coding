// Author : ysh
// 04/06/2022 Wed  8:11:20.57
#include<bits/stdc++.h>
using namespace std;
int main() {
    // freopen("0.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<pair<int,int>>f(n);
        int a,b;
        for(int i = 0;i<n;i++) {
            cin>>a>>b;
            f[i] = make_pair(a,b);
        }
        int c[101][101] = {};
        sort(f.begin(),f.end());
        for(int j = 1;j<=n;j++) {
            for(int i = 1;i<=100;i++) {
                int mmax = 0;
                int now = f[j - 1].first;
                int value = f[j - 1].second;
                if(i>=now) c[j][i] = max(max(c[j][i - 1],c[j - 1][i]),c[j - 1][i - now] + value);
                else c[j][i] = max(c[j][i - 1],c[j - 1][i]);
            }
        }
        // for(int i = 0;i<=100;i++) {
        //     for(int j = 0;j<=100;j++) {
        //         cerr<<c[j][i]<<" \n"[j == 100];
        //     }
        // }
        // for(int i = 0;i<=n;i++) {
        //     for(int j = 0;j<=100;j = j + 4) cerr<<c[i][j]<<" \n"[j == 100];
        // }
        // cerr<<"\n";
        cout<<c[n][100]<<"\n";
    }
    return 0;
}