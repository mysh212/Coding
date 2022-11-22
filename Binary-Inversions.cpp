// Author : ysh
// 11/22/2022 Tue  9:54:44.49
// https://codeforces.com/contest/1760/problem/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        bitset<(int) 2e5>f;
        f.set();
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            if(tmp == 1) f.reset(i);
        }
        int mmax = 0;
        bool d = 0;
        auto found = f._Find_first();
        for(int i = 0;i<=2;i++) {
            int ans = 0;
            int t = 0;
            for(int i = 0;i<n;i++) {
                if(!f.test(i)) t++;
                else ans += t;
            }
            mmax = max(mmax,ans);
            // cout<<f.test(0)<<" "<<f.test(1)<<"\n";
            if(i == 0) {
                if(!f.count() == (int) 0) f.reset(found = f._Find_first());
                else d = 1,i++;
            }
            if(i == 1) {
                if(!d) f.set(found);
                if(f.count() == (int) 2e5) continue;
                for(int i = n - 1;i >= 0;i--) {
                    if(!f.test(i)) {
                        f.set(i);
                        break;
                    }
                }
            }
        }
        cout<<mmax<<"\n";
    }
    return 0;
}