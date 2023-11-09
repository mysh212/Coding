// Author : ysh
// 2023/11/03 Fri 23:17:13
#include<bits/stdc++.h>
using namespace std;
#define eo(i) (now < 0 ? 0 : i) // (cerr<<i<<"\n",i)
// #define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>f(n);
    for(string &i : f) cin>>i;

    vector<vector<int>>mark(6,vector<int>(46));
    for(string &j : f) {
        int sig = 0;
        for(char &k : j) {
            sig = sig + (k - '0');
        }
        mark.at(j.size()).at(sig)++;
    }

    long long ans = 0;
    for(string i : f) {
        int t = i.size();
        
        vector<int>pre(i.size());
        pre.at(0) = i.at(0) - '0';
        for(int j = 1;j<t;j++) pre.at(j) = pre.at(j - 1) + (i.at(j) - '0');
        for(int j = 1;j<=t;j++) {
            int now = 0;
            if((t + j) & 1) continue;
            int len = (t + j) >> 1;
            // for(int k = 0;k<len;k++) now = now + (i.at(k) - '0');
            now = now + pre.at(len - 1);
            // for(int k = len;k<t;k++) now = now - (i.at(k) - '0');
            now = now - (pre.at(t - 1) - (len == 0 ? 0 : pre.at(len - 1)));
            ans = ans + eo(mark.at(j).at(now));
        }
        for(int j = 1;j<t;j++) {
            int now = 0;
            if((t + j) & 1) continue;
            int len = (t + j) >> 1;
            // for(int k = t - 1;k>(t - 1 - len);k--) now = now + (i.at(k) - '0');
            now = now + (pre.at(t - 1) - (pre.at(t - 1 - len) < 0 ? 0 : pre.at((t - 1 - len))));
            // for(int k = t - 1 - len;k>=0;k--) now = now - (i.at(k) - '0');
            now = now - pre.at(t - 1 - len);
            ans = ans + eo(mark.at(j).at(now));
        }
    }
    cout<<ans;
    return 0;
}