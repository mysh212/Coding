// Author : ysh
// 01/28/2023 Sat 13:19:54.71
// https://cses.fi/problemset/task/1076
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    int r = 0;
    for(int i = 0;i<b;i++) {
        t.insert((f.at(i) << 18) | r++);
    }
    int mid = b >> 1;
    if(!(b & 1)) mid = mid - 1;
    for(int i = b;i<a;i++) {
        cout<<(*t.find_by_order(mid) >> 18)<<" ";
        t.insert((f.at(i) << 18) | r++);
        t.erase(t.lower_bound(f.at(i - b) << 18));
    }
    cout<<(*t.find_by_order(mid) >> 18)<<" ";
    return 0;
}