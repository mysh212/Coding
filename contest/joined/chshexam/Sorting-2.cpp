// Author : ysh
// 09/19/2022 Mon  8:46:25.41
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>f;
    int n;cin>>n;
    int tmp;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        f.insert(tmp);
        ans += f.order_of_key(tmp);
    }
    cout<<ans;
    return 0;
}