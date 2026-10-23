// Author : ysh
// 2026/09/19 Sat 11:34:02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;

    vector<int>mark(n), ct(n);
    for(int &i : mark) cin>>i, ct.at(i)++;

    sort(f.begin(), f.end());
    int now = 0;

    multiset<int, greater<int>>s(mark.begin(), mark.end());
    for(int i = 0;i<n;i++) {
        auto found = s.lower_bound(i);

        // assert(found != s.end());
        if(found == s.end()) return cout<<"-1", 0;

        mark.at(i) = *found;
        s.erase(found);
    }

    vector<vector<int>>pre(n);
    for(int i = 0;i<n;i++) pre.at(mark.at(i)).push_back(i);

    vector<int>ans(n);
    for(auto &i : pre) {
        while(!i.empty()) {
            ans.at(i.back()) = f.at(now++);
            i.pop_back();
        }
    }

    reverse(ans.begin(), ans.end());
    for(int &i : ans) cout<<i<<" ";
    return 0;
}