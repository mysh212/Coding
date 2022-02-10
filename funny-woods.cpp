// Author : ysh
// 02/08/2022 Tue 22:41:20.72
// http://choj.me/problem/a053
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int f[n] = {};
    int k = 0;
    while(n--) {
        
        int a,b;cin>>a>>b;
        if(a == 1) {
            f[k] = b;
            k++;
        }
        if(a == 2) {
            k = k - b;
        }
        if(a == 3) {
            cout<<f[b]<<"\n";
        }
    }
    return 0;
}