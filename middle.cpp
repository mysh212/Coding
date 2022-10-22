// Author : ysh
// 10/15/2022 Sat  8:41:59.93
// https://www.luogu.com.cn/problem/P1168
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    int n;cin>>n;
    bool c = 1;
    int r = 0;
    while(n--) {
        int tmp;cin>>tmp;
        t.insert((tmp << 20) + ++r);
        if(c) cout<<((*t.find_by_order(t.size() >> 1)) >> 20)<<"\n";
        c = c ^ 1;
    }
    return 0;
}