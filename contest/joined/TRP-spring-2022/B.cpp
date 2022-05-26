// Author : ysh
// 05/08/2022 Sun 14:09:43.73
#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    for(int i = 0;i<n;i++) {
        cout<<check(f[i] - 1)<<" ";
    }
}
int check(int x) {
    if(x == 0) return 0;
    // if(x == 0) return -1;
    return check(x / 3) + (x % 3);
}