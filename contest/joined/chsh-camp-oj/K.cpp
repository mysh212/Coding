// Author : ysh
// 2023/07/07 Fri 16:12:57
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<bool>v(a);
    while(c--) {
        int tmp;cin>>tmp;
        v.at(tmp - 1) = 1;
    }

    vector<vector<pair<int,int>>>f[2];
    f[0] = f[1] = vector<vector<pair<int,int>>>(a);
    while(b--) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;b--;
        f[0].at(a).push_back({b,c});
        f[0].at(b).push_back({a,c});
        f[1].at(a).push_back({b,d});
        f[1].at(b).push_back({a,d});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[2];
    q[0].emplace(0,0);
    for(int i = 0;i<=1;i++) {
        vector<bool>mark(a);
        while(!q[i].empty()) {
            auto now = q[i].top();q[i].pop();
            int l = now.first;
            int d = now.second;
            if(i == 1 && d == a - 1) {
                cout<<l;
                return 0;
            }
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            cerr<<d<<" "<<l<<"\n";
            for(auto &j : f[i].at(d)) {
                if(i == 0) {
                    q[0].emplace(l + j.second,j.first);
                    if(v.at(j.first)) q[1].emplace(l + j.second,j.first);
                } else {
                    q[1].emplace(i + j.second,j.first);
                }
            }
        }
    }
    return -1;
}