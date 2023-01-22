// Author : ysh
// 01/20/2023 Fri 10:14:31.94
// https://tioj.ck.tp.edu.tw/problems/2248
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
#include<fast>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    vector<vector<pair<int,int>>>to(a);
    for(int j = 1;j<a;j++) {
        array<int,3> i;
        cin>>i[0]>>i[1]>>i[2];
        i[0]--;i[1]--;
        to.at(i[0]).push_back({i[1],i[2]});
        to.at(i[1]).push_back({i[0],i[2]});
    }
    int ans = 0;
    function<int(int,int)> check = [&] (int last,int x) {
        for(auto &i : to.at(x)) {
            if(i.first != last) {
                int tmp = check(x,i.first);
                debug(ans);
                ans = ans + abs(tmp) * i.second;
                f.at(x) = f.at(x) + tmp;
            }
        }
        return (f.at(x) - b);
    };
    check(-1,0);
    cout<<ans;
    return 0;
}