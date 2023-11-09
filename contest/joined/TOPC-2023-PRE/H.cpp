// Author : ysh
// 2023/09/16 Sat 10:52:41
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define sig(i) ((1 << i) - 1)
int siginv(int x) {
    int now = 1;
    int ans = 0;
    while(x > 0) {
        x = x - now;
        now = now << 1;
        ans++;
    }
    return ans;
}
#define int unsigned long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;

    int height = siginv(a);
    #define h height
    int left = sig(h) - a;
    
    int ans = 0;
    debug(height,left);
    function<void(int)> check = [&] (int x) {
        int larger = sig(h - (x - 1)) - min(left,(unsigned long long) (1 << (h - x))) - 1;
        int smaller = x - 1;
        if(smaller >= b || x > h) return;
        if(b >= smaller + 1 and b <= a - larger) {
            ans = ans + (1 << (x - 1));
        }
        debug(x,smaller + 1,a - larger);
        check(x + 1);
        return;
    };

    check(1);

    cout<<ans;
    return 0;
}