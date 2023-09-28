// Author : ysh
// 2023/06/21 Wed 07:36:10
// https://codeforces.com/contest/1843/problem/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<int>>f(n);
        for(int i = 1;i<n;i++) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }

        vector<int>big(n);
        function<int(int,int)> check = [&] (int last,int x) {
            int ans = 0;
            for(int &i : f.at(x)) {
                if(i != last) ans = ans + check(x,i);
            }
            if(x != 0 && f.at(x).size() == 1) return big.at(x) = 1;
            return big.at(x) = ans;
        };
        check(-1,0);

        int m;cin>>m;
        debug(big);
        while(m--) {
            int a,b;cin>>a>>b;
            cout<<big.at(a - 1) * big.at(b - 1)<<"\n";
        }
    }
    return 0;
}