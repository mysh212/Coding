// Author : ysh
// 08/25/2022 Thu  9:32:55.07
// https://cses.fi/problemset/task/1673
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int R = 1e13;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f[a];
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        f[a - 1].push_back({b - 1,c});
    }
    int mmax = -R;
    {
    vector<int>mark(a);
    bool c = 0;
    function<void(int,int,bool)> check = [&] (int n,int l,bool d) {
        if(c) return;
        if(n == a - 1) {
            if(d) c = 1;
            mmax = max(mmax,l);
        }
        bool e = 0;
        if(mark[n]) {
            e = 1;
            // return;
        }
        mark[n] = 1;
        for(auto i : f[n]) {
            check(i.first,l + i.second,e);
        }
        mark[n] = 0;
        return;
    };
    check(0,0,0);
    if(c) {
        cout<<-1;
        return 0;
    }
    }
    cout<<mmax;
    return 0;
}