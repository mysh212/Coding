// Author : ysh
// 07/03/2022 Sun 10:47:23
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        vector<int>f(a + 1);
        for(int i = 1;i<=a;i++) {
            cin>>f[i];
            f[i] = f[i - 1] + f[i];
        }
        for(int i = 0;i<b;i++) {
            int aa,bb;cin>>aa>>bb;
            cout<<f[bb] - f[aa - 1]<<"\n";
        }
    }
    return 0;
}