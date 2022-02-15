// Author : ysh
// 02/14/2022 Mon 13:06:32.40
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/J
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n+1] = {};
    int b[n+1] = {};
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        b[i] = b[i - 1] + a[i];
    }
    int mmax = 0;
    int tmp = 0;
    int mmin = 0;
    bool e = 1;
    for(int i = 0;i<=n;i++) {
        if((!e) && b[i] >= mmin) {
            continue;
        }
        e = 0;
        // for(int i : b) {
        //     cout<<i<<" ";
        // }
        // cout<<" "<<mmax<<"\n";
        tmp = b[i] + mmax;
        for(int j = i+1;j<=n;j++) {
            if(b[j] > tmp) {
                mmin = b[i];
                mmax = b[j] - b[i];
                tmp = b[j];
            }
            //mmax = max(mmax,b[j] - b[i]);
        }
    }
    cout<<(mmax >= 0 ? mmax : 0);
    return 0;
}