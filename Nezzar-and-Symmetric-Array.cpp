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

bool check(vector<int>&f) {
    multiset<int>s;
    for(int &i : f) {
        s.insert(i);
    }
    for(int &i : f) {
        if(s.count(i) != 2) return 0;
    }
    return 1;
}
int main() {
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
        int sig = 0;
        int r = n >> 1;
        cerr<<(int)c<<"\n";
        if(c) for(int &i : v) {
            if(((i >> 1) - sig) % r != 0 || (i & 1)) c = 0;
            sig = sig + (((i >> 1) - sig) / r);
            r = r - 1;
            debug(i,sig,r);
        }
        cout<<(c ? "YES\n" : "NO\n");
    }
}