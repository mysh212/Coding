// Author : ysh
// 2023/07/07 Fri 22:39:12
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int ans = 0;
        while(n--) {
            int a,b;cin>>a>>b;
            if(a - b > 0) ans++;
        }
        cout<<ans<<"\n";
    }
}