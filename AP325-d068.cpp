// Author : ysh
// 03/11/2022 Fri 13:17:52.89
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n+2] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    if(n == 1) {
        cout<<a[0];
        return 0;
    }
    if(n == 2) {
        cout<<min(a[0],a[1]);
        return 0;
    }
    a[2] += min(a[0],a[1]);
    for(int i = 3;i<n;i++) {
        a[i] = min(a[i - 3] + a[i],min(a[i - 2] + a[i],a[i - 1] + a[i]));
    }
    /*
    for(int i : a) {
        cout<<i<<" ";
    }
    cout<<"\n";
    */
    cout<<min(a[n - 1],a[n - 2]);
    return 0;
}