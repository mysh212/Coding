// Author : ysh
// 03/23/2022 Wed 14:02:57.99
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int c[n] = {};
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    sort(c,c+n);
    for(int i : c) {
        cout<<i<<" ";
    }
    return 0;
}