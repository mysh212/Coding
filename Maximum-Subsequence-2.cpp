// Author : ysh
// 12/07/2022 Wed 21:07:56.37
// https://codeforces.com/contest/888/problem/E
#include<bits/stdc++.h>
using namespace std;
int a,b;
set<int,greater<int>> check(int l,int r,vector<int>&f) {
    set<int,greater<int>>s;
    for(int i = 1,len = (1 << (r - l + 1));i < len;i++) {
        long long now = 0;
        int t = i;
        for(int j = l;j<=r;j++) {
            // cerr<<(t & 1);
            if(t & 1) now = now + f.at(j);
            t = t >> 1;
        }
        // cerr<<"\n";
        s.insert(now % b);
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    int r = a >> 1;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        i = i % b;
    }
    set<int,greater<int>>s(check(0,r,f));
    set<int,greater<int>>t(check(r + 1,a - 1,f));
    int mmax = max(*s.begin(),*t.begin());
    // for(int i : t) cerr<<i<<" ";
    for(int i : s) {
        mmax = max(mmax,(t.upper_bound(b - i) == t.end() ? 0 : *t.upper_bound(b - i)) + i);
    }
    cout<<mmax;
    return 0;
}