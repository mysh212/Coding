// Author : ysh
// 03/14/2023 Tue 14:49:54.35
// https://codeforces.com/problemset/problem/1478/C
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
bool check(vector<int>&f) {
    sort(f.rbegin(),f.rend());
    int last = 0;
    for(int i = 0,len = f.size();i<len;i++) {
        if((i & 1) && last != f.at(i)) return 0;
        last = f.at(i);
    }
    return 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        n = n << 1;
        vector<int>v(n);
        for(int &i : v) {
            cin>>i;
        }
        bool c = 0;
        c = check(v);
        sort(v.rbegin(),v.rend());
        v.resize(unique(v.begin(),v.end()) - v.begin());
        if(v.size() != (n >> 1)) c = 0;
        int sig = 0;
        int r = n >> 1;
        // cerr<<"\n";
        vector<int>ans;
        if(c) for(int &i : v) {
            if(((i >> 1) - sig) % r != 0 || (((i >> 1) - sig) / r) <= 0 || (i & 1)) c = 0;
            ans.push_back(((i >> 1) - sig) / r);
            sig = sig + (((i >> 1) - sig) / r);
            r = r - 1;
            // debug(i,sig,r,(((i >> 1) - sig) / (r + 1)));
        }
        debug(ans);
        cout<<(c ? "YES\n" : "NO\n");
    }
}