// Author : ysh
// 2023/11/03 Fri 23:01:21
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<pair<int,int>>f(m);
        for(auto &i : f) cin>>i.first>>i.second;

        vector<vector<int>>dt(m,vector<int>(m));
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<m;j++) {
                dt.at(i).at(j) = abs(f.at(i).first - f.at(j).first) + abs(f.at(i).second - f.at(j).second);
            }
        }

        vector<bool>mark(m);
        int now = 0;
        int ans = 0;
        for(int i = 0;i<m;i++) {
            cout<<f.at(now).first<<" "<<f.at(now).second<<"\n";
            mark.at(now) = 1;
            vector<pair<int,int>>tmp;
            for(int j = 0;j<m;j++) {
                if(now == j) continue;
                tmp.push_back(make_pair(dt.at(now).at(j),j));
            }
            sort(f.begin(),f.end());
            for(auto &k : tmp) {
                if(mark.at(k.second)) continue;
                now = k.second;
                ans = ans + k.first;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}