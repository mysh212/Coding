// Author : ysh
// 11/09/2022 Wed 15:36:31.29
// https://tioj.ck.tp.edu.tw/problems/2268
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i = 0;i<a;i++) {
            int tmp;cin>>tmp;
            q.emplace(tmp,i);
        }
        while(b--) {
            int tmp;cin>>tmp;
            if(tmp <= q.top().first) continue;
            auto now = q.top();q.pop();
            q.emplace(tmp,now.second);
        }
        int ans = q.top().first;
        int mmin = 0;
        vector<int>f(a);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            f.at(now.second) = now.first;
        }
        int last = 0;
        for(int &i : f) {
            i = last += i;
            ans = max(ans,i - mmin);
            mmin = min(i,mmin);
        }
        cout<<ans<<"\n";
    }
    return 0;
}