// Author : ysh
// 08/31/2022 Wed 15:25:26.08
// https://cses.fi/problemset/task/1197
#include<bits/stdc++.h>
using namespace std;
#define R __INT_MAX__ + 1
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f[a];
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a - 1].push_back({b - 1,c});
    }
    vector<int>dt(a,R);
    vector<bool>mark(a);
    vector<bool>ck(a);
    vector<int>s;
    vector<int>v;
    vector<int>::iterator t;
    function<bool(int,int)> check = [&] (int n,int c) {
        if(mark[n]) {
            auto now = (s.end());
            int sig = 0;
            while(now != s.begin()) {
                now = prev(now);
                sig = sig + v[now - s.begin()];
                if(*now == n) {
                    t = now;
                    break;
                }
            }
            if(sig < 0 && (s.end() - now) > 2) return 1;
            return 0;
        }
        ck[n] = 1;
        mark[n] = 1;
        s.push_back(n);
        v.push_back(c);
        for(auto &i : f[n]) {
            if(check(i.first,i.second)) return 1;
        }
        s.pop_back();
        v.pop_back();
        mark[n] = 0;
        return 0;
    };
    for(int i = 0;i<a;i++) {
        if(!ck[i]) if(check(i,0)) {
            cout<<"YES\n";
            cout<<s.back() + 1<<" ";
            for(;t != s.end();t = next(t)) {
                cout<<(*t) + 1<<" ";
            }
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}