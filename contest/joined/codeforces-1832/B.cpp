// Author : ysh
// 05/12/2023 Fri 22:43:43.97
#include<bits/stdc++.h>
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
        deque<int>f(a);
        for(int &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end());
        debug(f);
        
        int ans = LLONG_MIN;
        int right = accumulate(f.rbegin(),f.rbegin() + b,0LL);
        ans = max(ans,-right);
        auto l = f.begin();
        auto r = f.rbegin() + b - 1;
        for(int i = 0;i<b;i++) {
            right = right - *r + *l + *next(l);
            ans = max(ans,-right);
            r = prev(r);
            l = next(next(l));
        }
        cout<<accumulate(f.begin(),f.end(),0LL) + ans<<"\n";
    }
    return 0;
}