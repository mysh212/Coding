// Author : ysh
// 05/12/2023 Fri 23:04:09.79
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int n;cin>>n;
        vector<pair<int,bool>>f(n);
        for(auto &i : f) {
            cin>>i.first;
        }
        f.resize(unique(f.begin(),f.end()) - f.begin());
        n = f.size();
        for(int j = 1,len = n - 1;j<len;j++) {
            if(f.at(j).first >= f.at(j + 1).first && f.at(j).first < f.at(j - 1).first) f.at(j).second = 1;
            if(f.at(j).first <= f.at(j + 1).first && f.at(j).first > f.at(j - 1).first) f.at(j).second = 1;
        }
        int ans = 0;
        for(auto &i : f) {
            // cerr<<(int) i.second<<" ";
            if(!i.second) ans++;
        }
        // cerr<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}