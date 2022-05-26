// Author : ysh
// 05/23/2022 Mon  8:14:30.36
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int mn(int x) {
    int y = x;
    while(x /= 10) {
        y = x;
    }
    return y;
}
inline int app(int a,int b) {
    int bk = b,t = 0;
    while(b /= 10) {
        t++;
    }
    return ((a * ((int) pow(10,t + 1))) + bk);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout<<app(50,12345)<<"\n"<<mn(2);
    // return 0;
    
    int n;cin>>n;
    int r = 1;
    if(n <= 10) {
        cout<<n;
        return 0;
    }
    int ans = 9;
    // vector<int>f;
    vector<int>tmp[2];
    tmp[0].resize(10);
    iota(tmp[0].begin(),tmp[0].end(),0);
    //f.assign(tmp[0].begin(),tmp[0].end());
    int max = 17;
    for(int i = 0;i<max;i++) {
        int now = (i & 1);
        tmp[!(i & 1)].clear();
        for(int j : tmp[i & 1]) {
            for(int k = 1;k <= mn(j);k++) {
                int nn = app(k,j);
                tmp[!now].push_back(nn);
                if(nn <= n) ans++;
            }
        }
        r = r * 10;
    }
    int t = 0;
    // for(int i : f) {
    //     if(i <= n) cout<<i<<" ";
    //     if(i <= n) t++;
    // }
    //cout<<"\n";
    cout<<ans;
    return 0;
}