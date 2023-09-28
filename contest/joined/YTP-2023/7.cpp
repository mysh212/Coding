// Author : ysh
// 2023/07/18 Tue 18:34:53
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back({b,c});
        f.at(b).push_back({a,c});
    }

    function<vector<int>(int,int)> check = [&] (int x,int y) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,x);
        vector<int>dt(a,(int) 1e9);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;
            if(dt.at(d) != (int) 1e9) continue;
            dt.at(d) = l;
            for(auto &i : f.at(d)) {
                q.emplace(max(l,i.second),i.first);
            }
        }
        return dt;
    };

    while(c--) {
        int a,b;cin>>a>>b;
        a--;b--;

        vector<int> left = check(a,b);
        vector<int> right = check(b,a);

        int ans = INT_MAX;
        for(int i = 0;i<a;i++) {
            ans = min({left.at(i) + right.at(i),ans});
            for(auto &j : f.at(i)) {
                ans = min(max(left.at(i),right.at(j.first)),ans);
                ans = min(max(left.at(j.first),right.at(i)),ans);
            }
        }
        if(ans == (int) 2e9 || ans == INT_MAX) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}