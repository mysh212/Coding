// Author : ysh
// 03/04/2023 Sat 22:53:41.13
// https://judge.tcirc.tw/ShowProblem?problemid=d037
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    for(auto &i : f) {
        cin>>i.first;
    }
    for(auto &i : f) {
        cin>>i.second;
    }
    int ans = 0;
    sort(f.begin(),f.end());
    multiset<int>s;
    int l = 0;
    for(auto &i : f) {
        while(l != a && f.at(l).first - i.first <= b) {
            s.insert(f.at(l).second);
            l++;
        }
        if(!s.empty()) ans = max(ans,*prev(s.end()) - *s.begin());
        s.erase(s.lower_bound(i.second));
        // for(int i : s) cout<<i<<" ";
        // cout<<"\n";
    }
    cout<<ans;
    return 0;
}