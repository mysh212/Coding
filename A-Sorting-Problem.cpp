// Author : ysh
// 2023/09/03 Sun 14:12:20
// https://codeforces.com/gym/103373/problem/C
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    int n;cin>>n;
    long long ans = 0;
    while(n--) {
        int tmp;cin>>tmp;
        t.insert(tmp);
        ans = ans + (t.size() - (t.order_of_key(tmp) + 1));
    }
    cout<<ans;
    return 0;
}