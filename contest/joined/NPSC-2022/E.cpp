// Author : ysh
// 11/12/2022 Sat 11:28:23.60
#include<bits/stdc++.h>
using namespace std;
#define N 300000
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
    vector<int>f(n),l(n,-1),r(n,-1);
    map<int,int>mark;
    int last = 0;
    bool c = 0;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        if(tmp == 1) f.at(i) = last;
        else f.at(i) = last - 1;
        if(tmp == -1 && mark.find(f.at(i)) != mark.end()) {
            r.at(mark[f.at(i)]) = i;
            l.at(i) = mark[f.at(i)];
        }
        mark[f.at(i)] = i;
        last += tmp;
    }
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        a--;b--;
        if(a > b) swap(a,b);
        int ans = 0;
        queue<pair<int,int>>q;
        q.emplace(0,b);
        vector<bool>mark(n);
        while(!q.empty()) {
            auto now = q.front();q.pop();
            int dt = now.first;
            int d = now.second;
            // cerr<<d<<"\n";
            if(d == a) {
                cout<<dt<<"\n";
                break;
            }
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            if(d > 0 && (!mark.at(d - 1))) q.emplace(dt + 1,d - 1);
            if(d < n - 1 && (!mark.at(d + 1))) q.emplace(dt + 1,d + 1);
            if(l.at(d) != -1 && (!mark.at(l.at(d)))) q.emplace(dt + 1,l.at(d));
            if(r.at(d) != -1 && (!mark.at(r.at(d)))) q.emplace(dt + 1,r.at(d));
        }
        // while(b > a) {
        //     if(l.at(b) != -1 && l.at(b) >= a) b = l.at(b);
        //     else b = b - 1;
        //     ans++;
        // }
        // cout<<ans<<"\n";
    }
    return 0;
}