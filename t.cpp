// Author : ysh
// 03/07/2023 Tue 11:31:43.58
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
vector<int>f;
int n,k;
int check(int x) {
    int l = 0,r = n - 1;
    while(l <= r && f.at(l) + f.at(r) < x) r--;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        l = i;
        auto found = lower_bound(f.rbegin(),f.rend(),x - f.at(i));
        int dt = f.rend() - found - i;
        ans = ans + max(0LL,dt);
        // while(l <= r && f.at(l) + f.at(r) < x) r--;
        // if(l > r) break;
        // ans = ans + (r - l + 1);
    }
    debug(x,ans);
    return ans < k;
}
int ck(int l,int r) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(l,mid);
    return ck(mid,r);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.rbegin(),f.rend());

    int tmp = ck(-1e18,1e18);
    cout<<tmp;
    return 0;
}