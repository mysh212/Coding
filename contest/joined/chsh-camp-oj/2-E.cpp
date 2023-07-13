// Author : ysh
// 2023/07/09 Sun 09:18:37
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
vector<vector<long long>> input(int n) {
    vector<vector<long long>>f(n,vector<long long>(n,LLONG_MAX));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            long long tmp;cin>>tmp;
            f.at(i).at(j) = tmp;
        }
    }
    return f;
}
vector<long long> dt(vector<vector<long long>>&f,int n,int x) {
    vector<long long>ans(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.emplace(0,x);

    vector<bool>mark(n);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        ans.at(d) = l;
        for(int i = 0;i<n;i++) {
            if(f.at(d).at(i) != LLONG_MAX) q.emplace(l + f.at(d).at(i),i);
        }
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        int m;cin>>m;
        auto f = input(n);
        debug(f);

        while(m--) {
            int a,b;cin>>a>>b;
            a--;b--;
            long long c;cin>>c;
            if(f.at(a).at(b) <= c) {
                cout<<"0\n";
                continue;
            }
            // f.at(a).at(b) = f.at(b).at(a) = min(f.at(a).at(b),c);

            int ans = 0;
            auto l = f.at(b);
            auto r = f.at(a);
            debug(l,r);
            for(int i = 0;i<n;i++) l.at(i) = min(l.at(i),r.at(i) + c);
            for(int i = 0;i<n;i++) r.at(i) = min(r.at(i),l.at(i) + c);
            for(int i = 0;i<n;i++) {
                for(int j = i + 1;j<n;j++) {
                    debug(l.at(i) + r.at(j) + c,l.at(j) + r.at(i) + c,f.at(i).at(j));
                    if(min({f.at(i).at(j),l.at(i) + r.at(j) + c,l.at(j) + r.at(i) + c}) < f.at(i).at(j)) ans++;
                    f.at(i).at(j) = f.at(j).at(i) = min({f.at(i).at(j),l.at(i) + r.at(j) + c,l.at(j) + r.at(i) + c});
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}