// Author : ysh
// 2025/05/19 Mon 10:12:36
// https://vjudge.net/problem/UVA-1619
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool ok = 0;
    int n;
    while(cin>>n) {
        if(ok) nl;
        
        vc<int>f(n);
        cin>>f;

        vc<pair<int,int>>mk;
        vc<pair<int,int>>mark(n);
        re(i, n) {
            while(!mk.empty() && mk.back().first >= f.at(i)) mk.pop_back();
            mark.at(i).first = (mk.empty() ? -1 : mk.back().second);
            mk.push_back({f.at(i), i});
        }

        mk.clear();
        for(int i = n - 1;i>=0;i--) {
            while(!mk.empty() && mk.back().first >= f.at(i)) mk.pop_back();
            mark.at(i).second = (mk.empty() ? n : mk.back().second);
            mk.push_back({f.at(i), i});
        }

        vc<int>v(all(f));
        int last = 0;
        repo(&i, v) i = last += i;
        
        int mmax = 0;
        int l,r;l = r = -1;
        re(i, n) {
            // int x = mark.at(i).first;
            // int y = mark.at(i).second;
            int x,y;
            tie(x,y) = mark.at(i);
            int rr = v.at(y - 1);
            int ll = (x == -1 ? 0 : v.at(x));
            
            if((rr - ll) * f.at(i) > mmax) {
                mmax = (rr - ll) * f.at(i);
                r = y - 1;
                l = x + 1;
            }
        }
        outl(mmax);
        outs(l + 1);
        outl(r + 1);
        ok = 1;
    }
    return 0;
}