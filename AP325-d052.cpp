// Author : ysh
// 03/11/2022 Fri 12:45:02.06
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int hold = 0;
    int ans = 0;
    int mmin = 0;
    int tmp;
    while(n--) {
        cin>>tmp;
        tmp += hold;
        hold = tmp;
        mmin = min(tmp,mmin);
        ans = max(tmp - mmin,ans);
    }
    cout<<ans;
    return 0;
}