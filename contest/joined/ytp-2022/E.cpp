// Author : ysh
// 07/22/2022 Fri 16:35:52
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define N 1000000007
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,int>m({{-1,0}});
    int n;cin>>n;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        // ans++;
        int t = 0;
        for(int j = -2;j<=2;j++) {
            auto ff = m.find(tmp + j);
            if(ff != m.end()) {
                t += ff->second;
                t = t % (N);
            }
        }
        ans = (ans + (t + 1)) % (N);
        // m[tmp] = (m[tmp] + t + 1) % (N);
        auto found = m.find(tmp);
        if(found != m.end()) found->second = (found->second + t + 1) % (N);
        else m.insert({tmp,(t + 1) % (N)});
    }
    cout<<ans;
    return 0;
}
