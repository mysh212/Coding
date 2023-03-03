// Author : ysh
// 03/03/2023 Fri 17:09:25.71
// https://codeforces.com/contest/1796/problem/D
// NF
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
        int a,b,c;cin>>a>>b>>c;
        vector<int>f(a);
        int last = 0;
        for(int &i : f) {
            cin>>i;
            i = i - c;
            i = last += i;
        }
        c = c << 1;
        if(b == 0) continue;

        vector<pair<int,int>>v({{f.at(0),0}});
        int mmax = f.at(0);
        int mmin = 0;
        debug(f);
        for(int i = 1;i<a;i++) {
            int now = f.at(i);
            for(int j = v.size() - 1;j>=0;j--) {
                auto nnow = v.at(j);
                int r = now + (c * (i - nnow.second));
                if(i - nnow.second > b) break;
                mmax = max(mmax,r - nnow.first);
            }
            if(i >= b - 1) mmin = min(f.at(i - b + 1),mmin);
            mmax = max(mmax,i + (c * b) - mmin);
            if(now < v.back().first) v.emplace_back(now,i);
            debug(v,mmax,now);
        }
        cout<<mmax<<"\n";
    }
    return 0;
}