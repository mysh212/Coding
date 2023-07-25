// Author : ysh
// 2023/07/18 Tue 17:09:03
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }

    int now,ot,last;now = ot = 0;last = -1;
    bool c = 0;
    int t = 0;
    for(int &i : f) {
        ot += i;
        if(ot >= 0) now += ot,ot = 0,last = t;
        t++;
    }
    debug(now,ot);
    t = 0;
    vector<pair<int,int>>ans(n);
    for(int &i : f) {
        ans.at(t++).second = now;
        if((!c && last >= t - 1) || c) {
            now -= i;
            ot += i;
        }
        if(ot >= 0) now += ot,ot = 0,last = t - 1,c = 1;
        debug(now,ot,last,t - 1);
    }

    t = 0;
    now = ot = 0;last = -1;
    for(int &i : f) {
        ot += i;
        if(ot <= 0) now += ot,ot = 0,last = t;
        t++;
    }
    c = 0;
    t = 0;
    for(int &i : f) {
        ans.at(t++).first = now;
        if((!c && last >= t - 1) || c) {
            now -= i;
            ot += i;
        }
        if(ot <= 0) now += ot,ot = 0,last = t - 1,c = 1;
    }
    for(auto &i : ans) cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}