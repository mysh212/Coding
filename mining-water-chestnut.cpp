// Author : ysh
// 02/13/2022 Sun 16:21:43.29
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/J
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int ans = 0;
    int a[16] = {};
    while(n--) {
        int tmp;cin>>tmp;
        int hold = 0;
        for(int i = 0;i<15;i++) {
            int t = tmp % 10;
            a[i] = a[i] + t + hold;
            hold = a[i] / 10;
            a[i] = a[i] % 10;
            if(t == 0&&hold == 0) {
                break;
            }
            tmp = tmp / 10;
        }
    }
    bool on = 0;
    for(int i = 14;i>=0;i--) {
        if(a[i]<0) {
            cout<<"0";
            return 0;
        }
    }
    for(int i = 14;i>=0;i--) {
        if(a[i] == 0&&on == 0) continue;
        on = 1;
        cout<<a[i];
    }
    return 0;
}