// Author : ysh
// 2023/07/07 Fri 14:18:47
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int a,b;
int dt(vector<vector<int>>&f,int x) {
    queue<pair<int,int>>q;
    vector<int>ans(a,-3);
    q.push({0,x});
    ans[x] = 0;
    int mmin = INT_MAX;
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int d = now.second;
        int l = ans.at(d);

        for(int i : f.at(d)) {
            if(ans.at(i) >= 0) {
                debug(ans[i],l);
                if(ans.at(i) >= l) mmin = min(ans.at(i) + l + 1,mmin);
            } else {
                q.push({l + 1,i});
                debug(ans[i]);
                ans.at(i) = l + 1;
                debug(ans[i]);
            }
        }
    }
    debug(ans);
    debug(mmin);
    return mmin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 1;i<=b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    
    int ans = INT_MAX;
    for(int i = 0;i<a;i++) {
        ans = min(dt(f,i),ans);
    }
    if(ans == INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}