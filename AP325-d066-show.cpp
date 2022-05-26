// Author : ysh
// 04/27/2022 Wed 13:56:04.22
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
    }
    for(int i = 1;i<n;i++) {
        if(i >= 2) f[i] = min(f[i - 1],f[i - 2]) + f[i];
        else if(i >= 1) f[i] = min(f[i - 1],0) + f[i];
    }
    cout<<f[n - 1];
    return 0;
}