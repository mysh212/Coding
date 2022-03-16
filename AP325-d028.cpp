// Author : ysh
// 03/09/2022 Wed 10:38:11.99
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    //freopen("1.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f;
    f.push_back(make_pair(INT_MAX,0));
    int tmp,ans = 0;
    for(int i = 1;i<=n;i++) {
        cin>>tmp;
        while(f.back().first <= tmp) f.pop_back();
        ans += i - f.back().second;
        f.push_back(make_pair(tmp,i));
    }
    cout<<ans;
    return 0;
}