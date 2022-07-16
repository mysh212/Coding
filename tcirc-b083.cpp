// Author : ysh
// 07/15/2022 Fri 19:34:26
// https://judge.tcirc.tw/ShowProblem?problemid=b083
#include<bits/stdc++.h>
using namespace std;
// #define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
    // int r[2000][2000];
    int l[2000] = {0};
    int ll[2000] = {0};
    int mmax = 0;
    for(int i = 0;i<a;i++) {    
        for(int j = 0;j<b;j++) {
            int tmp;
            cin>>tmp;
            l[j] = (tmp == 7 ? l[j] + 1:0);
        }
        for(int k = 0;k<b;k++) {
            ll[k] = l[k];
            for(int j = k+1;j<b;j++) {
                ll[j] = min(ll[j - 1],l[j]);
                mmax = max(mmax,min((j - k + 1),ll[j]));
            }
        }
    }
    cout<<mmax<<"\n";
    }
}
