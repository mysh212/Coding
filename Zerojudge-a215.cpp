// Author : ysh
// 06/21/2022 Tue  8:02:48.12
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        int i = a + 1;
        int sig = a;
        while(sig <= b) {
            sig += i++;
        }
        cout<<i - 1 - a + 1<<"\n";
    }
    return 0;
}