// Author : ysh
// 2024/05/16 Thu 22:43:13
// https://codeforces.com/contest/1883/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) cin>>i;

        int ans = 0;
        int last = -1;
        int zzz = 0;
        for(int &i : f) {
            if(last == -1) {
                last = i;
                continue;
            }
            if(!(last <= i)) {
                int pre = ceil(log2(last * 1.0 / i));
                zzz += pre;
                ans += zzz;
            }
            last = i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}