// Author : ysh
// 06/14/2022 Tue  9:00:43.90
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(b);
    for(int &i : f) {
        cin>>i;
    }
    for(int &i : g) {
        cin>>i;
    }
    int sig = 0;
    int ans = INT_MIN;
    // for(int l = 0;l <= 1;l++) {
        // for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                int pi = 0;
                sig = 0;
                for(int k = j;k<b;k++) {
                    // cout<<1;
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[k];
                    // printf("%d %d\n",pi - 1,k);
                    ans = max(ans,sig);
                    if(pi >= a) {
                        pi = 0;
                        sig = 0;
                        continue;
                    }
                }
                sig = 0;
                for(int k = 0;k<j;k++) {
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[k];
                    // printf("%d %d\n",pi - 1,k);
                    ans = max(ans,sig);
                    if(pi >= a) {
                        pi = 0;
                        sig = 0;
                        continue;
                    }
                }
            }
        // }
        // reverse(g.begin(),g.end());
    // }

            for(int j = 0;j<b;j++) {
                int pi = 0;
                sig = 0;
                for(int k = j;k >= 0;k--) {
                    // printf("%d %d\n",pi,k);
                    // cout<<1;
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[k];
                    // printf("%d %d\n",pi - 1,k);
                    ans = max(ans,sig);
                    if(pi >= a) {
                        pi = 0;
                        sig = 0;
                        continue;
                    }
                }
                sig = 0;
                for(int k = b - 1;k>j;k--) {
                    // printf("%d %d\n",pi,k);
                    if(sig < 0) sig = 0;
                    sig += f[pi++] * g[k];
                    // printf("%d %d\n",pi - 1,k);
                    ans = max(ans,sig);
                    if(pi >= a) {
                        pi = 0;
                        sig = 0;
                        continue;
                    }
                }
            }
    cout<<ans;
    return 0;
}