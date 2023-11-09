// Author : ysh
// 2023/09/04 Mon 10:28:07
// https://tioj.ck.tp.edu.tw/problems/1208
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
const int R = (int) 2e8;
int n;
vector<int>f;
int check(int x) {
    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    t.insert(0);
    int ans = 0;
    int last = 0;
    int r = 1;
    for(int i = 0;i<n;i++) {
        last = last + f.at(i);
        if(not (t.lower_bound((last + 1) << 16) == t.end())) ans = ans + abs(t.order_of_key(*t.lower_bound((last + 1) << 16)) - t.order_of_key(*t.lower_bound((last - x) << 16)));
        else ans = ans + (t.size() - t.order_of_key(*t.lower_bound((last - x) << 16)));
        // debug(last,(t.size() - t.order_of_key(*t.lower_bound(last - x))));
        t.insert((last << 16) + r++);
    }
    return ans;
}
int ck(int l,int r,int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    debug(l,r,mid,(((n * (n + 1)) >> 1) - check(mid)),check(mid));
    bool c = (((n * (n + 1)) >> 1) - check(mid)) < k;
    if(c) return ck(l,mid,k);
    else return ck(mid + 1,r,k);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b,(not(a == b && b == 0))) {
        ::n = a;
        f.resize(a);
        for(int &i : f) {
            cin>>i;
        }
        // cerr<<check(0);
        cout<<ck(-R,R,b)<<"\n";
    }
    return 0;
}