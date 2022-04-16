// Author : ysh
// 04/11/2022 Mon 20:29:35.44
// http://choj.me/problem/b032
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    // int tmp = f[0];
    // n = f.size();
    int c[102] = {};
    for(int i = 0;i<n;i++) {
        c[f[i]] = max(c[f[i] - 1] + 1 , c[f[i]]);
        for(int j = f[i] + 1;j<=100;j++) {
            c[j] = max(c[j - 1],c[j]);
        }
    }
    // for(int i : c) cout<<i<<" ";
    // cout<<"\n";
    cout<<(n == 1 ? 1 : c[100]);
    return 0;
}