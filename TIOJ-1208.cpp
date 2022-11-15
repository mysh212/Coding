// Author : ysh
// 11/07/2022 Mon 18:04:36.30
// https://tioj.ck.tp.edu.tw/problems/1208
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
// #define int long long
int check(int n,int k,vector<int>&f) {
    tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>t;
    int ans = 0;
    long long r = 1;
    t.insert(1);
    for(int &i : f) {
        // for(auto i : t) cout<<(i >> 15)<<" ";
        // cout<<"\n";
        auto found = t.lower_bound(((i - k + 1) * 1LL) << 28);
        if(found == t.end()) ans += t.size();
        else ans += t.order_of_key(*found);
        t.insert(((i * 1LL) << 28) + ++r);
    }
    // cerr<<t.order_of_key(1);
    return ans;
}
int ck(int n,int k,int l,int r,vector<int>&f) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    // cerr<<l<<" "<<r<<"\n";
    // if(l == 15) exit(-1);
    // if(check(n,mid,f) == k) return mid;
    int ans = check(n,mid,f);
    cerr<<ans<<" "<<k<<"\n";
    // if(ans == k) return mid;
    if(ans >= k) return ck(n,k,mid,r,f);
    if(ans < k) return ck(n,k,l,mid,f);
    return -1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        if(a == 0 && b == 0) return 0;
        vector<int>f(a);
        int last = 0;
        for(int &i : f) {
            cin>>i;
            i = last += i;
            // cerr<<i<<" ";
        }
        // b = ((a * (a + 1)) >> 1) - b;
        // cout<<check(a,1000,f);
        cout<<ck(a,b,-(a * 10000 + 1),a * 10000 + 1,f)<<"\n";
    }
    return 0;
}