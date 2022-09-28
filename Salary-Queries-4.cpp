// Author : ysh
// 09/20/2022 Sun  9:47:00.78
// https://cses.fi/problemset/task/1144
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>f;
    int a,b;cin>>a>>b;
    vector<int>v(a);
    int t = 0;
    for(int &i : v) {
        cin>>i;
        f.insert((i << 20) + t++);
    }
    f.insert(LONG_LONG_MAX);
    for(int i = 0;i<b;i++) {
        char tmp;cin>>tmp;
        if(tmp == '!') {
            int b,c;cin>>b>>c;
            f.erase(f.lower_bound(v.at(b - 1) << 20));
            f.insert((c << 20) + t++);
            v.at(b - 1) = c;
            continue;
        }
        int a,b;cin>>a>>b;
        cout<<f.order_of_key(*f.lower_bound(((b + 1) << 20))) - f.order_of_key(*f.lower_bound(a << 20))<<"\n";
    }
    return 0;
}