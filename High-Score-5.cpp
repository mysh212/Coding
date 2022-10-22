// Author : ysh
// 10/10/2022 Mon  8:29:12.94
// https://cses.fi/problemset/task/1673
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

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,-c});
        // f.at(b).push_back({a,-c});
    }
    vector<int>dt(a,1e13);
    dt.at(0) = 0;
    for(int i = 0;i<a - 1;i++) {
        for(int r = 0;r < a;r++) {
            auto &j = f.at(r);
            for(auto &k : j) {
                dt.at(k.first) = min(dt.at(k.first),dt.at(r) + k.second);
            }
        }
    }
    // for(int i : dt) cerr<<i<<" ";
    // cerr<<"\n";
    vector<bool>mark(a);
    vector<bool>mk(a);
    vector<bool>re(a);
    function<bool(int,bool)> check = [&] (int x,bool c) {
        // cerr<<x<<" ";
        if(x == a - 1) return c;
        if((!c) && mark.at(x)) return false;
        if((c) && mk.at(x)) return false;
        if(re.at(x)) c = 1;
        mark.at(x) = 1;
        if(c) mk.at(x) = 1;
        for(auto &i : f.at(x)) {
            if(check(i.first,c)) return true;
        }
        return false;
    };
    function<bool(int,bool)> checkn = [&] (int x,bool c) {
        // cerr<<x<<" ";
        if(c) if(x == a - 1) return true;
        if(!c) mark = vector<bool>(a);
        if(mark.at(x)) return false;
        mark.at(x) = 1;
        for(auto &i : f.at(x)) {
            if(checkn(i.first,1)) return true;
        }
        return false;
    };
    bool o = 0;
    for(int r = 0;r < a;r++) {
        auto &j = f.at(r);
        for(auto &k : j) {
            if(dt.at(r) + k.second < dt.at(k.first)) {
                // re.at(r) = 1;
                // re.at(k.first) = 1;
                o = 1;
                re.at(r) = 1;
                re.at(k.first) = 1;
            }
        }
    }
    // for(bool i : re) cerr<<(int) i<<" ";
    // cerr<<"\n";
    if(o && (check(0,0) || checkn(a - 1,0))) {
        cout<<-1;
        return 0;
    }
    cout<<-dt.at(a - 1);
    return 0;
}