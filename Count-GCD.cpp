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
//#define int long long
vector<bool>f(46341);
vector<int>prime;
vector<int> check(int x) {
    vector<int>f;
    for(int &i : prime) {
        if(x == 1 || i * i > x) break;
        if(x % i == 0) f.push_back(i);
        while(x % i == 0) {
            x = x / i;
        }
    }
    if(x != 1) f.push_back(x);
    return f;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 2;i<46341;i++) { if(!f[i]) { prime.push_back(i); for(int j = i * i;j<46341;j+=i) { f[j] = 1; } } }
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
        vector<int>fre(check(f.at(0)));
        function<int(int,int)> ck = [&] (int x,int t) {
            int rr = b;
            rr = rr / t;
            vector<int>re;
            for(int &i : fre) {
                if(x % i == 0) re.push_back(i);
            }
            int n = re.size();
            long long ans = 0;
            for(int i = 1,len = (1 << n);i<len;i++) {
                long long now = 1;
                int t = 0;
                for(int j = 0;j<n;j++) {
                    if((i >> j) & 1) {
                        now = now * re.at(j);
                        t++;
                    }
                }
                if((t & 1)) ans = ans + (rr / now);
                else ans = ans - (rr / now);
            }
            return rr - ans;
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
