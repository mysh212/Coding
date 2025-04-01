// Author : ysh
// 2024/12/05 Thu 01:07:07
// BP
#include<bits/stdc++.h>
using namespace std;
#include<slow>
// #include<fast>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        vc<vc<pair<int,int>>>f(a);
        re(b) {
            int a,b,c;cin>>a>>b>>c;
            a--;b--;

            f.at(a).push_back({b,c});
            f.at(b).push_back({a,c});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,1);
        vc<bool>mark(a);
        vc<int>dt(a);

        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;

            if(mark.at(d)) continue;
            mark.at(d) = 1;
            dt.at(d) = l;

            for(auto &i : f.at(d)) {
                q.emplace(l + i.second,i.first);
            }
        }
        
        vc<int>mk(a, -1);
        function<int(int)> check = [&] (int x) {
            if(mk.at(x) != -1) return mk.at(x);
            if(x == 1) return 1LL;
            int ans = 0;
            for(auto &i : f.at(x)) {
                if(dt.at(i.first) < dt.at(x)) ans += check(i.first);
            }
            return mk.at(x) = ans;
        };

        cout<<check(0)<<"\n";
    }
    return 0;
}