// Author : ysh
// 2023/09/05 Tue 08:18:34
// https://codeforces.com/contest/1042/problem/D
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }

    tree<pair<int,int>,null_type,greater<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>t;
    t.insert({0,0});
    int r = 1;
    int ans = 0;
    int last = 0;
    for(int &i : f) {
        last = last + i;
        int now = (last - b + 1);

        auto found = t.upper_bound({now,0});
        if(found != t.end()) ans = ans + (t.order_of_key(*found));
        else ans += t.size();

        // for(int i : t) cerr<<(i >> 16)<<" ";
        // cerr<<"\n";

        t.insert({(last),r++});
    }

    cout<<ans;
    return 0;
}