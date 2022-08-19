// Author : ysh
// 08/19/2022 Fri 16:06:54.19
// https://cses.fi/problemset/task/1672
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
#define INT_MAX 1e18
struct box{
    int l,d,f;
    box(int a = 0,int b = 0,int f = 0):
        l(b), d(a), f(f) {};
    bool operator<(const box a) const {
        return l > a.l;
    }
};
#define MAX 505
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a + 1,vector<int>(a + 1,INT_MAX));
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a][b] = min(f[a][b],c);
        f[b][a] = f[a][b];
        // f[b].push_back(box(a,c));
    }
    // check(0,a - 1);
    for(int i = 0;i<=a;i++) {
        f[i][i] = 0;
    }
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=a;j++) {
            if(i == j) continue;
            for(int k = j + 1;k<=a;k++) {
                if(i == k) continue;
                // cout<<i<<j<<"\n";
                f[j][k] = min(f[j][k],f[j][i] + f[i][k]);
                f[k][j] = f[j][k];
            }
        }
    } 
    // for (int k = 1; k <= a; k++){
    //     for (int i = 1; i <= a; i++){
    //         if (i == k) continue;
    //         for (int j = i + 1; j <= a; j++){
    //             if (j == k) continue;
    //             if (f[i][j] > f[i][k] + f[k][j]){
    //                 f[i][j] = f[i][k] + f[k][j];
    //                 f[j][i] = f[i][j];
    //             }
    //         }
    //     }
    // }
    while(c--) {
        int a,b;cin>>a>>b;
        if(a > b) swap(a,b);
        if(a == b) {
            cout<<0<<"\n";
            continue;
        }
        cout<<(f[a][b] == INT_MAX ? -1 : f[a][b])<<"\n";
    }
    return 0;
}