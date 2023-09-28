// Author : ysh
// 2023/08/14 Mon 11:32:33
// https://codeforces.com/contest/1784/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());

        long long now = 1,ans = 0;
        for(int i = 0;i<n;i++) {
            if(f.at(i) > now) {
                ans = ans + (f.at(i) - now);
                now++;
                continue;
            }
            if(f.at(i) == now) now++;
        }

        cout<<ans<<" ";
    }
    return 0;
}