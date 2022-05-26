// Author : ysh
// 04/18/2022 Mon 22:23:28.08
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int s[7];
    int id = 0;
}a[200000];
int now = 0;
int rk[200000][7] = {};
inline bool cp(box a,box b) {
    if(a.s[now] == b.s[now]) return a.id<b.id;
    return a.s[now] > b.s[now];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int sig = 0;
        a[i].id = i + 1;
        for(int j = 0;j<6;j++) {
            cin>>a[i].s[j];
            sig += a[i].s[j];
        }
        a[i].s[6] = sig;
    }
    for(int i = 0;i<=6;i++) {
        now = i;
        sort(a,a+n,cp);
        for(int j = 0;j<n;j++) {
            rk[(a[j].id - 1)][i] = j + 1;
        }
    }
    // for(int i = 0;i<n;i++) {
    //     for(int j = 0;j<7;j++) {
    //         cout<<rk[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cin>>n;
    int a,b;
    for(int i = 0;i<n;i++) {
        cin>>a>>b;
        cout<<rk[a - 1][b - 1]<<"\n";
    }
    return 0;
}