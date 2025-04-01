// Author : ysh
// 2024/12/06 Fri 13:22:44
// https://atcoder.jp/contests/abc382/tasks/abc382_c
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<pair<int,int>>f;
    re(i,a) {
        int x;cin>>x;
        if(f.empty() || f.back().second > x) f.push_back({i,x});
    }

    re(b) {
        int now;cin>>now;
        auto found = lower_bound(all(f), now, [](pair<int,int>a,int b) {
            return a.second > b;
        });
        if(found == f.end()) cout<<"-1";
        else cout<<found->first + 1;
        
        nl;
    }
    return 0;
}