// Author : ysh
// 04/09/2023 Sun 14:09:51.27
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(a);
    for(int &i : f) {
        cin>>i;
    }
    for(int &i : g) {
        cin>>i;
    }
    vector<int>v(b);
    for(int &i : v) {
        cin>>i;
        i--;
    }
    sort(v.begin(),v.end());

    priority_queue<pair<int,int>>q;
    int ans = 0;
    int j = 0;
    for(int i : v) {
        int sig = 0;
        while(!q.empty()) q.pop();
        for(int k = i;k >= j;k--) {
            q.emplace(0,g.at(k));
            int now = f.at(k);
            while(now != 0 && !q.empty()) {
                auto t = q.top();q.pop();
                int r = t.first;
                int x = t.second;
                if(r == 0) ans++;
                if(x > now) {
                    x = x - now;
                    now = 0;
                    q.emplace(1,x);
                } else {
                    now = now - x;
                }
            }
            if(now != 0) {
                cout<<-1;
                return 0;
            }
        }
        j = i + 1;
    }
    cout<<ans;
    return 0;
}