// Author : ysh
// 02/06/2022 Sun 17:47:51.21
// http://choj.me/problem/00072
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<bool>f(n + 1);
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        f[tmp] = 1;
    }
    for(int i = 0;i<=n;i++) {
        if(f[i] == 0) {
            cout<<i;
            break;
        }
    }
    return 0;
}