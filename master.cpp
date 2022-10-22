// Author : ysh
// 10/16/2022 Sun  9:01:26.79
// https://www.luogu.com.cn/problem/P4933
#include<bits/stdc++.h>
using namespace std;
#define R 998244353
int c[1000][40001] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int sig = 0;
    for(int i = 0;i<n;i++) {
        for(int j = i - 1;j >= 0;j--) {
            // if(i == 1) c[j][f[i] - f[j]] += 1;
            c[i][f[i] - f[j] + 20000] += c[j][f[i] - f[j] + 20000] + 1;
            c[i][f[i] - f[j] + 20000] = c[i][f[i] - f[j] + 20000] % R;
            sig = sig + c[j][f[i] - f[j] + 20000] + 1;
            sig = sig % R;
        }
    }
    cout<<(sig + n) % R;
    return 0;
}