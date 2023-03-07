// Author : ysh
// 03/03/2023 Fri 17:09:25.71
// https://codeforces.com/contest/1796/problem/D
// NF
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
        int a,b,c;cin>>a>>b>>c;
        deque<int>f(a);
        int last = 0LL;
        for(int &i : f) {
            cin>>i;
            i = i - c;
            i = last += i;
        }
        c = c << 1;
        // if(b == 0) continue;
        f.push_front(0LL);
        a = a + 1;
        vector<pair<int,int>>v({{f.at(0),0}});

        int ans = 0LL;
        // debug(f);
        int mmin = 0;
        if(c > 0) {
            for(int i = 1;i<a;i++) {
                if(f.at(i) < v.back().first) v.emplace_back(f.at(i),i);
                auto found = v.rbegin();
                while(found != v.rend()) {
                    if(found->second == i) found = next(found);
                    // debug(i,*found);
                    if(i - found->second > b) break;
                    ans = max(ans,(f.at(i) - found->first) + c * min(b,(i - found->second)));
                    found = next(found);
                }
                if(i - b >= 0) {
                    mmin = min(f.at(i - b),mmin);
                    ans = max(ans,f.at(i) - mmin + max(0LL,c * b));
                }
            }
        } else {
            for(int i = 1;i<a;i++) {
                if(f.at(i) < v.back().first) v.emplace_back(f.at(i),i);
                auto found = v.rbegin();
                while(found != v.rend()) {
                    if(found->second == i) found = next(found);
                    debug(i,*found);
                    if(i - found->second > b) break;
                    ans = max(ans,(f.at(i) - found->first) + max(c * max(((i - found->second) - ((a - 1) - b)),0LL),c * min(b,i - found->second)));
                    found = next(found);
                }
                if(i - b >= 0) {
                    mmin = min(f.at(i - b),mmin);
                    ans = max(ans,f.at(i) - mmin + c * b);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}