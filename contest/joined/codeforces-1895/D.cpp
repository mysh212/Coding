// Author : ysh
// 2023/11/04 Sat 00:04:47
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    if(n & 1) {
        int ans = 0;
        for(int i = 0;i<n;i++) ans = ans ^ i;

        vector<int>f(n - 1);
        for(int &i : f) cin>>i;

        int now = 0;
        for(int i = 0;i<n;i = i + 2) now = now ^ f.at(i);

        ans = ans ^ now;
        vector<int>aans;
        aans.push_back(ans);
        reverse(f.begin(),f.end());
        for(int &i : f) {
            ans = ans ^ i;
            aans.push_back(ans);
        }
        reverse(aans.begin(),aans.end());

        for(int &i : aans) cout<<i<<" ";
        return 0;
    }

    cout<<"0 ";
    vector<int>f(n - 1);
    int now = 0;
    for(int &i : f) cin>>i,cout<<__builtin_popcount(now = now ^ i)<<" ";
    return 0;
}