// Author : ysh
// 2023/06/21 Wed 08:37:53
// https://codeforces.com/contest/1843/problem/F1
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int R = (int) 2e5 + 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<pair<int,int>>now(n + 1),ans(n + 1);
        int t = 1;
        ans.at(0) = now.at(0) = {0,1};
        while(n--) {
            char tmp;cin>>tmp;
            if(tmp == '+') {
                int a,b;cin>>a>>b;
                a--;
                now.at(t) = {min(now.at(a).first + b,0),max(0,now.at(a).second + b)};
                ans.at(t) = {min(ans.at(a).first,now.at(t).first),max(ans.at(a).second,now.at(t).second)};
                t++;
            }
            debug(ans.at(1));
            if(tmp == '?') {
                int a,b,c;cin>>a>>b>>c;
                a--;b--;
                assert(a == 0);
                if(c >= ans.at(b).first && c <= ans.at(b).second) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
    return 0;
}