// Author : ysh
// 2023/06/21 Wed 08:13:45
// https://codeforces.com/contest/1843/problem/E
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
    while(n--) {
        int a,b;cin>>a>>b;
        vector<pair<int,int>>f(b);
        for(auto &i : f) cin>>i.first>>i.second,i.first--,i.second--;
        int m;cin>>m;
        vector<int>q(m);
        for(int &i : q) cin>>i,i--;

        function<bool(int)> check = [&] (int x) {
            vector<int>pre(a);
            for(int i = 0;i<x;i++) {
                pre.at(q.at(i)) = 1;
            }
            int last = 0;
            for(int &i : pre) {
                i = last += i;
            }
            for(auto &i : f) {
                if(((pre.at(i.second) - (i.first == 0 ? 0 : pre.at(i.first - 1))) << 1) > i.second - i.first + 1) return true;
            }
            // debug(x,pre);
            return false;
        };

        function<int(int,int)> ck = [&] (int l,int r) {
            if(l == r) return l;
            int mid = (l + r) >> 1;
            if(check(mid)) return ck(l,mid);
            else return ck(mid + 1,r);
        };

        int ans = ck(1,m + 1);
        if(ans == m + 1) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}