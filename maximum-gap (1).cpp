// Author : ysh
// 03/18/2022 Fri 21:32:49.54
#include<bits/stdc++.h>
using namespace std;
int main() {
    //freopen("0.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    long long tmp;
    long long mmin = 0,ans = 0;
    long long hold = 0;
    long long c[n+1] = {};
    for(int i = 1;i<=n;i++) {
        cin>>tmp;
        c[i] = hold + tmp;
        hold += tmp;
    }
    for(int i = 0;i<=n;i++) {
        for(int j = i;j<=n;j++) {
            ans = max(ans,c[j] - c[i]);
        }
    }
    cout<<ans;
    return 0;
}