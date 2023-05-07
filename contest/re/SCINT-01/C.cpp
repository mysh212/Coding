// Author : ysh
// 05/06/2023 Sat 21:05:00.90
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

    int a,b,c;cin>>a>>b>>c;
    vector<vector<bool>>f(a,vector<bool>(b));
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            int tmp;cin>>tmp;
            f.at(i).at(j) = (tmp >= c);
        }
    }

    vector<vector<int>>g(a,vector<int>(b));
    for(int i = 0;i<a;i++) {
        g.at(i).at(0) = (f.at(i).at(0) ? 1 : 0);
        for(int j = 1;j<b;j++) {
            if(f.at(i).at(j)) g.at(i).at(j) = g.at(i).at(j - 1) + 1;
        }
    }

    debug(g);
    vector<pair<int,int>>mark;
    int ans = 0;
    for(int i = 0;i<b;i++) {
        mark.clear();
        for(int j = 0;j<a;j++) {
            auto found = lower_bound(mark.begin(),mark.end(),make_pair(g.at(j).at(i),0),[] (pair<int,int>a,pair<int,int>b) {
                return a.first < b.first;
            });
            bool tmp = (found == mark.end());
            int r = -1;
            if(!tmp) r = found->second;
            if(g.at(j).at(i) == 1) ans = max(ans,1);
            if(found != mark.end()) ans = max(ans,min(g.at(j).at(i),j - found->second + 1));
            while(!mark.empty() && mark.back().first > g.at(j).at(i)) mark.pop_back();
            if(tmp) mark.push_back({g.at(j).at(i),j});
            else mark.push_back({g.at(j).at(i),r});
            debug(mark);
        }
    }
    cout<<ans * ans;
    return 0;
}