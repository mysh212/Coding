// Author : ysh
// 09/03/2022 Sat 19:28:03.83
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>f;
        int t = 0;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            f.insert((tmp << 18) + t++);
            cout<<(i + 1) - (f.order_of_key(*f.lower_bound((tmp << 18))))<<"\n";
        }
    }
    return 0;
}