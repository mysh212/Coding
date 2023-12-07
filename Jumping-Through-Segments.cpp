// Author : ysh
// 2023/12/06 Wed 23:19:17
// https://codeforces.com/contest/1907/problem/D
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vc<pair<int,int>>f(n);
        repo(&i,f) cin>>i.first>>i.second;

        function<bool(int)> check = [&] (int x) {
            int l,r;l = r = 0;
            repo(&i,f) {
                l = l - x;
                r = r + x;
                l = max(l,i.first);
                r = min(i.second,r);
                if(l > i.second || r < i.first) return false;
            }
            return true;
        };
        
        int l,r;l = 0,r = INT_MAX;
        while(l != r) {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        outl(l);
    }
    return 0;
}