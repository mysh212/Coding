// Author : ysh
// 2023/08/24 Thu 16:08:06
// https://codeforces.com/contest/1359/problem/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
#include<table>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n + 1);
    for(int &i : f) {
        cin>>i;
    }
    
    for(int i = 1;i<=n;i++) {
        g.at(i) = g.at(i - 1) + f.at(i - 1);
    }

    table<int>mmax(g,[] (int a,int b) {
        return max(a,b);
    }),mmin(g);

    vector<int>mark,left(n),right(n);
    int t = 0;
    for(int &i : f) {
        while(!mark.empty() && f.at(mark.back()) <= i) mark.pop_back();
        left.at(t) = (mark.empty() ? -1 : mark.back() + 1);
        mark.push_back(t++);
    }
    mark.clear();

    for(int i = n - 1;i>=0;i--) {
        while(!mark.empty() && f.at(mark.back()) <= f.at(i)) mark.pop_back();
        right.at(i) = (mark.empty() ? n - 1 : mark.back() - 1);
        mark.push_back(i);
    }

    int ans = 0;
    for(int i = 0;i<n;i++) {
        if(f.at(i) >= 0) ans = max(ans,mmax.get(i + 1,right.at(i) + 1) - mmin.get(left.at(i) + 1,i) - f.at(i));
    }
    debug(f);
    debug(g);
    debug(left);
    debug(right);

    cout<<ans;
    return 0;
}