// Author : ysh
// 2023/12/06 Wed 23:35:12
// https://codeforces.com/contest/1907/problem/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,int>>f(n);
        for(auto &i : f) cin>>i.first>>i.second;

        function<bool(int)> check = [&] (int x) {
            int l,r;l = r = 0;
            for(auto &i : f) {
                l = l - x;
                r = r + x;
                l = max(l,i.first);
                r = min(i.second,r);
                if(l > i.second || r < i.first) return false;
            }
            return true;
        };

        function<int(int,int)> ck = [&] (int l,int r) {
            if(l == r) return l;
            int mid = (l + r) >> 1;
            if(check(mid)) return ck(l,mid);
            return ck(mid + 1,r);
        };

        cout<<ck(0,INT_MAX)<<"\n";
    }
    return 0;
}