// Author : ysh
// 2023/07/18 Tue 18:05:49
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
    while(n--) {
        int n;cin>>n;
        vector<array<int,3>>f(n);
        for(auto &i : f) {
            cin>>i[0]>>i[1]>>i[2];
            int tmp = __gcd(i[0],__gcd(i[1],i[2]));
            i[0] = i[0] / tmp;
            i[1] = i[1] / tmp;
            i[2] = i[2] / tmp;
        }
        debug(f);
        sort(f.begin(),f.end());
        f.resize(unique(f.begin(),f.end()) - f.begin());
        n = f.size();

        vector<long double>ans;
        cerr<<fixed<<setprecision(10);
        int t = 0;
        for(auto &i : f) {
            long double a = i[0],b = i[1],c = i[2];
            if(a == b && b == 0) continue;
            if(b * b - a * c * 4 < 0) {
                t++;
                continue;
            }
            if(a == 0) {
                ans.push_back(-c * 1.0 / b);
                debug(i,ans.back());
            } else {
                long double aa = ((-b * 1.0) + sqrtl(b * b - a * c * 4)) / (a * 2);
                long double bb = ((-b * 1.0) - sqrtl(b * b - a * c * 4)) / (a * 2);
                // debug(aa,bb);
                debug(i,aa,bb);
                // cout<<fixed<<setprecision(10)<<a<<"\n"<<b<<"\n\n\n";
                ans.push_back(aa);
                ans.push_back(bb);
            }
        }

        sort(ans.begin(),ans.end());
        ans.resize(unique(ans.begin(),ans.end()) - ans.begin());
        debug(ans);
        debug(ans.size(),t);
        cout<<ans.size() + (t << 1)<<"\n";
    }
    return 0;
}