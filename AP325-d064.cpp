// Author : ysh
// 07/18/2022 Mon  9:39:51.29
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<int,int>m;
    vector<int>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
    }
    for(int i = n - 1;i>=0;i--) {
        auto found = m.upper_bound(-f[i]);
        
    }
}