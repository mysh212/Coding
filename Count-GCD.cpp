// Author : ysh
// 11/22/2022 Tue 11:17:46.40
// https://codeforces.com/problemset/problem/1750/D
#include<bits/stdc++.h>
using namespace std;
const int R = 998244353;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int> check(int x) {
    vector<int>f;
    for(int i = 2;i<=x;i++) {
        if(x % i == 0) f.push_back(i);
        while(x % i == 0) {
            x = x / i;
        }
    }
    return f;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a);
        int last = 0;
        bool c = 0;
        for(int &i : f) {
            cin>>i;
            if(last != 0) {
                if(last % i != 0) c = 1;
            }
            last = i;
        }
        if(c) {
            cout<<"0\n";
            continue;
        }
        function<int(int,int)> ck = [&] (int x,int t) {
            int rr = b;
            rr = rr / t;
            vector<int>re(check(x));
            debug(x,rr,re);
            for(int &i : re) {
                rr = rr - (rr / i);
            }
            debug(rr);
            return rr;
        };
        vector<int>v;
        for(int i = 1;i<a;i++) {
            if(f.at(i - 1) == 1) {
                v.push_back(b);
                continue;
            }
            v.push_back(ck(f.at(i - 1) / f.at(i),f.at(i)));
        }
        long long ans = 1;
        debug(v);
        for(int i : v) {
            ans = (ans * 1LL * i) % R;
        }
        cout<<ans<<"\n";
    }
    return 0;
}