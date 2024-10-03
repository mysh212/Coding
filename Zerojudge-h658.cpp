// Author : ysh
// 2024/09/30 Mon 00:35:51
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.first>>i.second;

    #define dt(i) (((i.first - a) * (i.first - a)) + ((i.second - b) * (i.second - b)))

    auto ans = *min_element(f.begin(),f.end(), [&](pair<int,int>x,pair<int,int>y) {
        return dt(x) < dt(y);
    });

    cout<<ans.first<<" "<<ans.second;
    return 0;
}