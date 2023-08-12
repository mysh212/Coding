// Author : ysh
// 2023/07/28 Fri 16:01:16
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int R = 21610411;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    long long ans = 0;
    vector<int>prime;
    bitset<(int) 1e6 + 1>s;
    s.reset();

    for(int i = 1;i<=n;i++) {
        if(s.test(i)) continue;
        long long sig = 1,now = 1;
        int j = 2;
        while(i * (j * j) <= n) {
            s.set(i * (j * j));
            sig = sig + j;
            j++;
        }
        debug(sig,i);
        ans = ans + (sig * sig) * i;
        ans = ans % R;
    }
    cout<<ans;
    return 0;
}