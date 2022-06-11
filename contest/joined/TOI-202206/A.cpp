// Author : ysh
// 06/10/2022 Fri 17:06:24.02
#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(200000);
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        f[tmp]++;
    }
    for(int i = MAX - 2;i >= 0;i--) {
        f[i] = f[i + 1] + f[i];
        if(f[i] >= i) {
            cout<<i;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}