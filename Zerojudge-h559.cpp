// Author : ysh
// 01/19/2023 Thu 15:21:11.29
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
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    vector<vector<pair<int,int>>>to(a);
    for(int j = 1;j<a;j++) {
        array<int,3> i;
        cin>>i[0]>>i[1]>>i[2];
        i[0]--;i[1]--;
        to.at(i[0]).push_back({i[1],i[2]});
        to.at(i[1]).push_back({i[0],i[2]});
    }
    int ans = 0;
    function<int(int,int)> check = [&] (int last,int x) {
        vector<pair<int,int>>t;
        vector<int>mark(a);
        vector<bool>mk(a);
        t.push_back({last,x});
        int now = 0;
        while(!t.empty()) {
            debug(t);
            int last = t.back().first;
            int x = t.back().second;
            if(!mk.at(x)) for(auto &i : to.at(x)) {
                if(i.first != last) {
                    t.push_back({x,i.first});
                }
            }
            if(mk.at(x)) {
                for(auto &i : to.at(x)) {
                    if(i.first != last) {
                        int tmp = mark.at(i.first);
                        ans = ans + abs(tmp) * i.second;
                        f.at(x) = f.at(x) + tmp;
                    }
                }
                mark.at(x) = (f.at(x) - b);
                t.pop_back();
            }
            mk.at(x) = 1;
        }
        return 0;
    };
    check(-1,0);
    cout<<ans;
    return 0;
}