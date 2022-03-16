// Author : ysh
// 03/11/2022 Fri  9:24:35.96
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    for(int &i : a) {
        cin>>i;
    }
    for(int i = 2;i<n;i++) {
        a[i] = min(a[i - 1],a[i - 2]) + a[i];
    }
    cout<<a[n - 1];
    return 0;
}