// Author : ysh
// 11/02/2022 Wed  9:20:11.51
// https://cses.fi/problemset/task/1133
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n);
    for(int i = 0;i<n - 1;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    vector<int>child(n,1),dt(n);
    int d = 0;
    function<void(int,int,int)> check = [&] (int last,int x,int level) {
        // cerr<<last<<" "<<x<<"\n";
        d = d + level;
        for(int &i : f.at(x)) {
            if(i == last) continue;
            check(x,i,level + 1);
            child.at(x) = child.at(x) + child.at(i);
        }
        return;
    };
    function<void(int,int)> ck = [&] (int last,int x) {
        for(int &i : f.at(x)) {
            if(i == last) continue;
            dt.at(i) = dt.at(x) - (child.at(i) << 1) + n;
            ck(x,i);
        }
        return;
    };
    check(-1,0,0);
    dt.at(0) = d;
    ck(-1,0);
    for(int &i : dt) cout<<i<<" ";
    return 0;
}