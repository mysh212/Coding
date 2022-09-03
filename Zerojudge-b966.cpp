// Author : ysh
// 09/02/2022 Fri 23:13:39.96
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) {
        cin>>i.first>>i.second;
    }
    sort(f.begin(),f.end());
    int ans = 0;
    int l = 0;
    for(auto i : f) {
        // cerr<<i.first<<" "<<i.second<<" "<<ans<<"\n";
        if(i.second < l) continue;
        ans += i.second - max(l,i.first);
        l = i.second;
    }
    cout<<ans;
    return 0;
}