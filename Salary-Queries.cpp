// Author : ysh
// 08/17/2022 Wed  8:06:09.40
// https://cses.fi/problemset/task/1144/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>f;
    vector<int>v(a);
    int t = 0;
    for(int &i : v) {
        cin>>i;
        f.insert((i << 20) + t++);
    }
    f.insert(LONG_LONG_MAX);
    for(int i = 0;i<b;i++) {
        string a;cin>>a;
        if(a == "?") {
            int a,b;cin>>a>>b;
            cout<<f.order_of_key(*f.lower_bound((b + 1) << 20)) - f.order_of_key(*f.lower_bound(a << 20))<<"\n";
        }
        if(a == "!") {
            int a,b;cin>>a>>b;
            f.erase(f.lower_bound(v[a - 1] << 20));
            f.insert((b << 20) + t++);
            v[a - 1] = b;
            // cout<<f.order_of_key(b) - f.order_of_key(a) + 1;
        }
    }
    return 0;
}