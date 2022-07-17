// Author : ysh
// 07/16/2022 Sat 14:55:13.37
// https://judge.tcirc.tw/ShowProblem?problemid=d031
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,int>m({{0,1}});
    int a,b;cin>>a>>b;
    int c = 0,mmax = 0;
    int last = 0;
    for(int i = 0;i<a;i++) {
        int now;cin>>now;
        now = last += now;
        auto found = m.lower_bound(now - b);
        if(found != m.end()) {
            if(now - found->first > mmax) {
                mmax = now - found->first;
                c = found->second;
            } else if(now - found->first == mmax) {
                c += found->second;
            }
        }
        m[now]++;
    }
    cout<<mmax<<"\n"<<c;
    return 0;
}