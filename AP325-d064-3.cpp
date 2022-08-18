// Author : ysh
// 08/17/2022 Wed 21:36:49.08
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>f;
    int n;cin>>n;
    int t = 0;
    int ans = 0;
    vector<int>v(n);
    for(int &i : v) {
        cin>>i;
    }
    for(int i = n - 1;i>=0;i--) {
        int tmp = v[i];
        f.insert((tmp << 20) + t++);
        ans += f.order_of_key(*f.lower_bound(tmp << 20));
    }
    cout<<ans;
    return 0;
}