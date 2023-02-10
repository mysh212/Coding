// Author : ysh
// 01/23/2023 Mon  7:40:36.31
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        tree<pair<int,int>,null_type,greater<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>t;
        int tt = 1;
        while(n--) {
            int tmp;cin>>tmp;
            t.insert({tmp,tt++});
            // cerr<<t.upper_bound({tmp,0})->second;
            cout<<t.order_of_key(*t.upper_bound({tmp + 1,0})) + 1<<"\n";
        }
    }
    return 0;
}