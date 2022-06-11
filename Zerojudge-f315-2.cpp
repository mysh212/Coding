// Author : ysh
// 06/10/2022 Fri 16:06:50.34
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<200000>b;
    int n;cin>>n;
    vector<int>f(n,-1),l(n,-1);
    for(int i = 0;i<(n << 1);i++) {
        int aa;cin>>aa;
        if(f[aa - 1] == -1) f[aa - 1] = i;
        else l[aa - 1] = i;
    }
    debug(f);
    debug(l);
    int ans = 0;
    for(int i = 0;i<n;i++) {
        b.set(f[i]);
        b.set(l[i]);
        for(int i = f[i] + 1;i<l[i];i++) {
            if(b.test(i)) ans++;
        }
        debug(ans);
    }
    cout<<ans;
    return 0;
}