// Author : ysh
// 03/18/2022 Fri 21:32:49.54
// https://192.168.193.20/problem/10
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
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        tmp = hold = hold + tmp;
        mmin = min(tmp,mmin);
        ans = max(ans,tmp - mmin);
    }
    cout<<ans;
    return 0;
}