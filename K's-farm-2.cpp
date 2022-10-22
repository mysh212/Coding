// Author : ysh
// 10/19/2022 Wed 13:39:28.74
// https://www.luogu.com.cn/problem/P1993
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

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a + 1);
    for(int i = 1;i<=a;i++) f.at(0).emplace_back(i,0);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        if(a == 3) {
            f.at(b).emplace_back(c,0);
            f.at(c).emplace_back(b,0);
            continue;
        }
        int d;cin>>d;
        if(a == 1) {
            f.at(b).emplace_back(c,-d);
            continue;
        }
        f.at(c).emplace_back(b,d);
    }
    queue<int>q;
    vector<int>dt(a + 1,(int) 1e4),t(a + 1);
    dt.at(0) = 0;
    q.emplace(0);
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(auto &i : f.at(now)) {
            if(dt.at(i.first) > dt.at(now) + i.second) {
        // cerr<<1;
                dt.at(i.first) = dt.at(now) + i.second;
                q.emplace(i.first);
                if(++t.at(i.first) > a) break;
            }
        }
    }
    debug(t);debug(dt);
    for(int i = 0;i<=a;i++) {
        for(auto &j : f.at(i)) {
            // cerr<<i<<" "<<j.first<<" "<<j.second<<"\n";
            if(dt.at(j.first) > dt.at(i) + j.second) {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}