// Author : ysh
// 12/08/2022 Thu 17:46:10.79
// https://cses.fi/problemset/task/1628/
// TLE
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

multiset<long long> check(int l,int r,vector<int>&f) {
    int n = (r - l + 1);
    multiset<long long>s({0});
    // cerr<<n<<"\n";
    for(int i = 1,len = (1 << n);i<len;i++) {
        int t = i;
        long long sig = 0;
        for(int j = l;j<=r;j++) {
            // debug(j);
            if(t & 1) sig = sig + f.at(j);
            t = t >> 1;
        }
        s.insert(sig);
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    int mid = a >> 1;
    for(int &i : f) {
        cin>>i;
    }
    multiset<long long>ll(check(0,mid,f)),rr(check(mid + 1,a - 1,f));
    // debug(ll,rr);
    long long ans = 0;
    for(long long i : rr) {
        if(i > b) continue;
        long long r = ll.count(b - i);
        ans += r;
    }
    cout<<ans;
    return 0;
}