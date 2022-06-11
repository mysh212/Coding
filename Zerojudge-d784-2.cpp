// Author : ysh
// 06/10/2022 Fri 13:52:41.37
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;vector<int>f(m);for(int &i : f) cin>>i;int mmax = INT_MIN;int ans = 0;for(int i : f) {ans = max(i,ans + i);mmax = max(mmax,ans);}cout<<mmax<<"\n";
    }
    return 0;
}