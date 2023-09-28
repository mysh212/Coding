// Author : ysh
// 05/08/2023 Mon 21:10:37.56
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define R 1000000007
#define int long long
pair<int,int> operator+(pair<int,int>a,pair<int,int>b) {
    return make_pair(a.first + b.first,a.second + b.second);
}
int fp(int a,int b) {
    if(b == 1) return a;
    int tmp = fp(a,b >> 1);
    if(b & 1) return (((tmp * tmp) % R) * a) % R;
    else return (tmp * tmp) % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    if(b == 3 || b == 1) {
        cout<<1<<"\n";
        return 0;
    }
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    
    vector<int>big(a);
    function<pair<int,int>(int,int)> check = [&] (int last,int x) {
        int n = 0;
        int sig = 0;
        for(int &i : f.at(x)) {
            if(i == last) continue;
            auto tmp = check(x,i);
            sig = sig + tmp.first;
            n = n + tmp.second;
        }
        big.at(x) = n + 1;
        // ans = ans + sig;
        return make_pair(sig + n + 1,n + 1);
    };

    
    int ans = 0;
    function<void(int,int,int)> ck = [&] (int last,int x,int now) {
        debug(x,now);
        ans = ans + now;
        for(int &i : f.at(x)) {
            if(i != last) {
                ck(x,i,now - big.at(i) + (a - big.at(i)));
            }
        }
        return;
    };

    ck(-1,0,check(-1,0).first - a);
    debug(big);
    debug(ans);
    int all = (((a * (a - 1)) >> 1) % R);
    ans = ans >> 1;
    debug(all);
    debug(fp(all,R - 1 - 1));
    cout<<(((ans + all) % R) * fp(all,R - 1 - 1)) % R;
    return 0;
}