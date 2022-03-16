// Author : ysh
// 03/11/2022 Fri 10:19:19.43
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
    a[2] = a[0] + a[2];
    for(int i = 3;i<n;i++) {
        a[i] = a[i] + max(a[i - 2],a[i - 3]);
    }
    cout<<max(a[n - 1],a[n - 2]);
    return 0;
}