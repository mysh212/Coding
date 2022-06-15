// Author : ysh
// 06/15/2022 Wed  0:31:45.79
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a);
        vector<bool>g(a);
        for(int i = 0;i<a;i++) {
            cin>>f[i];
            if(i != 0) {
                if((f[i] << 1) > f[i - 1]) {
                    g[i] = 1;
                }
            }
        }
        g[0] = g[1];
        int ans = 0;
        bool last = g[0];
        // for(bool i : g) cout<<(int) i << " ";
        // cout<<"\n";
        int l = 0;
        for(int i = 0;i<a;i++) {
            // cout<<ans<<" "<<l<<" ";
            if(last != g[i] && g[i] == 0) {
                ans = ans + max(l - b,0);
                l = 0;
            }
            if(g[i]) l++;
            last = g[i];
        }
        if(g[a - 1] == 1) {
            ans = ans + max(l - b,0);
            l = 0;
        }
        cout<<ans<<"\n";
    }
    return 0;
}