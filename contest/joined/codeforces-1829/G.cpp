// Author : ysh
// 05/06/2023 Sat 23:57:32.53
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define int long long
vector<int>mark;
void init() {
    int t = 2;
    for(int i = 1;i<=(int) 2e6;i += t++) {
        mark.push_back(i);
    }
    // debug(mark);
    return;
}
pair<int,int> whoami(int x) {
    if(x == 1) return make_pair(1,1);
    auto found = lower_bound(mark.begin(),mark.end(),x);
    return {(found - mark.begin() + 1),x - *prev(found) - 1};
}
int whatisthis(pair<int,int>x) {
    if(x == make_pair(1LL,0LL)) return 1;
    if(x.first <= 1 || x.second < 0 || mark.at(x.first - 2) + x.second + 1 > mark.at(x.first - 1)) return -1;
    return mark.at(x.first - 2) + x.second + 1;
}
pair<int,int> up(int x) {
    auto tmp = whoami(x);
    return make_pair(whatisthis({tmp.first - 1,tmp.second - 1}),whatisthis({tmp.first - 1,tmp.second}));
}
bitset<(int) 1e6 + 1>ans;
void check(int x,int l,int r) {
    // debug(x,l,r);
    if(x == 1) return ans.set(1),void();
    auto tmp = whatisthis({x,l});
    for(int i = 0;i<=(r - l);i++) {
        ans.set(tmp + i);
    }
    check(x - 1,max(0LL,l - 1),min(x - 2,r));
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        ans.reset();
        check(whoami(n).first,whoami(n).second,whoami(n).second);
        int r = 0;
        for(int i = ans._Find_first();i<=(int) 1e6;i = ans._Find_next(i)) {
            r = r + (i * i);
        }
        cout<<r<<"\n";
    }
    return 0;
}