// Author : ysh
// 02/03/2023 Fri 23:25:11.24
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        int t = 0;
        vector<pair<int,int>>f(a);
        for(auto &i : f) {
            ++t;
            int mmin = min(t,a + 1 - t);
            cin>>i.first;
            i.second = i.first;
            i.first = i.first + mmin;
            i.second = i.second + t;
        }
        sort(f.begin(),f.end());
        vector<int>pre(a);
        for(int i = 0;i<a;i++) {
            pre.at(i) = (i >= 1 ? pre.at(i - 1) : 0) + f.at(i).first;
        }
        debug(f);
        debug(pre);

        int ans = 0;
        for(int i = 0;i<a;i++) {
            if(f.at(i).second > b) continue;
            auto found = upper_bound(pre.begin(),pre.end(),b - f.at(i).second);
            int index = found - pre.begin() - 1;
            debug(index);
            if(index >= i) {
                found = upper_bound(pre.begin(),pre.end(),b);
                index = found - pre.begin() - 1;
                index--;
            }
            
            ans = max(ans,index + 2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}