// Author : ysh
// 09/06/2022 Tue 20:39:14.93
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>f;
    int n;cin>>n;
    vector<int>ii(n,-1),o(n);
    for(int i = 0;i<(n << 1);i++) {
        int tmp;cin>>tmp;
        tmp--;
        if(ii[tmp] != -1) {
            o[tmp] = i;
            continue;
        }
        ii[tmp] = i;
    }
    f.insert((n << 1) + 1);
    long long ans = 0;
    for(int i = 0;i<n;i++) {
        ans += ((f.order_of_key(*f.lower_bound(o[i])) - f.order_of_key(*f.lower_bound(ii[i]))));
        f.insert(ii[i]);
        f.insert(o[i]);
    }
    cout<<ans;
    return 0;
}