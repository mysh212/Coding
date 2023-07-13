// Author : ysh
// 2023/07/07 Fri 23:27:53
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        long long n;cin>>n;
        bool o = 0;
        for(int i = 2;i<=64;i++) {
            if(o) continue;
            long long tmp = pow(n,1.0 / i);
            for(long long j = max(2LL,tmp - 3);j <= tmp + 3;j++) {
                int ans = 0;
                int last = 1;
                for(int k = 0;k<=i;k++) ans = ans + last,last = last * j;
                if(ans == n) o = 1;
            }
        }
        if(o) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}