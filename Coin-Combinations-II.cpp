// Author : ysh
// 07/30/2022 Sat 18:58:36.52
// https://cses.fi/problemset/task/1636
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int) 1e6 + 5;
const int r = (int) 1e9 + 7;
int c[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        // c[i] = 1;
    }
    c[0] = 1;
    for(int j = 0;j<a;j++) {
        for(int i = 1;i<=b;i++) {
            if(i - f[j] > 0) {
                // cerr<<"c["<<i<<"] += c["<<i - f[j]<<"] == "<<c[i - f[j]]<<"\n";
                c[i] += c[i - f[j]];
                c[i] = c[i] % r;
            } else if(i == f[j]) {
                c[i] += 1;
                c[i] = c[i] % r;
            }
            // cout<<c[i]<<" ";
        }
        // cout<<"\n";
    }
    cout<<c[b];
    return 0;
}