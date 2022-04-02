// Author : ysh
// 03/27/2022 Sun 18:20:19.30
#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        if(n == 0) break;
        int ans = 0;
        // printf("%d\n",n&1);
        while(1) {
            if(!(n & 1)) {
                break;
            } else {
                ans++;
                n = n >> 1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}