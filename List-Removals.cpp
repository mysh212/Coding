// Author : ysh
// 08/20/2022 Sat 10:18:31.00
// https://cses.fi/problemset/task/1749
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    int n;cin>>n;
    vector<int>f(n);
    int r = 0;
    for(int &i : f) {
        cin>>i;
        t.insert(r++);
    }
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        int now = *t.find_by_order(tmp - 1);
        cout<<f.at(now)<<" ";
        t.erase(now);
    }
    return 0;
}