// Author : ysh
// 2023/11/06 Mon 15:24:28
// https://codeforces.com/contest/1895/problem/D
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
    vector<int>f(n - 1);
    for(int &i : f) cin>>i;
    
    for(int i = 1,len = n - 2;i<=len;i++) {
        f.at(i) = f.at(i) ^ f.at(i - 1);
    }
    
    vector<int>mark(30);
    for(int i : f) {
        int t = 0;
        while(i != 0) {
            mark.at(t++) += i & 1;
            i = i >> 1;
        }
    }
    
    vector<int>mk(30);
    for(int i = 1;i<n;i++) {
        int tmp = i;
        int t = 0;
        while(tmp != 0) {
            mk.at(t++) += tmp & 1;
            tmp = tmp >> 1;
        }
    }
    
    vector<bool>ans(30);
    for(int i = 0;i<30;i++) {
        if(mark.at(i) != mk.at(i)) ans.at(i) = 1;
    }
    
    int now = 0;
    reverse(ans.begin(),ans.end());
    for(bool i : ans) {
        now = now << 1;
        if(i) now = now | 1;
    }

    debug(mark);
    debug(mk);
    
    cout<<now<<" ";
    for(int i : f) cout<<(now ^ i)<<" ";
    return 0;
}
