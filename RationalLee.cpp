// Author : ysh
// 2023/10/24 Tue 17:24:06
// https://codeforces.com/problemset/problem/1369/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n,k;cin>>n>>k;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }

        sort(f.begin(),f.end());
        int ans = 0;
        ans = accumulate(f.rbegin(),f.rbegin() + k,0LL);

        vector<int>v(k);
        for(int &i : v) {
            cin>>i;
        }

        sort(v.begin(),v.end());
        int now = 0;
        int nowr = n - 1;
        for(int i = k - 1;i>=0;i--) {
            if(v.at(i) == 1) {
                ans = ans + f.at(nowr--);
                continue;
            }
            ans = ans + f.at(now);
            now = now + max(v.at(i) - 1,1LL);
        }

        cout<<ans<<" ";
    }
    return 0;
}