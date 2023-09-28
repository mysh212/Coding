// Author : ysh
// 2023/08/08 Tue 19:03:17
// https://codeforces.com/contest/1814/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        int n = max(a,b);
        int ans = a + b;
        for(int i = 2;i<=1e6;i++) {
            ans = min(ans,(a / i) + (b / i) + (a % i == 0 ? 0 : 1) + (b % i == 0 ? 0 : 1) + (i - 1));
            // cout<<(a / i) + (b / i) + (a % i == 0 ? 0 : 1) + (b % i == 0 ? 0 : 1) + (i - 1)<<" ";
        }
        cout<<ans<<"\n";
    }
    return 0;
}