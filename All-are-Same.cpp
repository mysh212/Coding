// Author : ysh
// 02/07/2023 Tue 10:08:43.72
// https://codeforces.com/problemset/problem/1593/D1
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        int mmin = INT_MAX;
        int ans = -1;
        for(int &i : f) cin>>i,mmin = min(i,mmin);
        for(int &i : f) i = i - mmin;
        for(int &i : f) {
            if(i == 0) continue;
            if(ans == -1) ans = i;
            ans = __gcd(ans,i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}