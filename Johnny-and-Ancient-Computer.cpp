// Author : ysh
// 2024/11/20 Wed 16:19:48
// https://codeforces.com/contest/1362/problem/A
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
        if(a == 0 && b == 0) {
            cout<<0<<"\n";
            continue;
        }
        if(a < b) swap(a,b);
        int ans;
        int tmp = 0;
        if(a % b != 0) goto no;

        ans = (a / b);
        // debug(ans, __lg(ans));
        // cerr<<__builtin_popcount(ans)<<"|\n";
        if((1ull << __lg(ans)) != ans) goto no;
        // while(not (ans & 1)) tmp++,ans = ans >> 1;

        cout<<(__lg(ans) + (3 - 1)) / 3;

        yes:
        cout<<"\n";
        continue;

        no:
        cout<<"-1\n";
        continue;
    }
}