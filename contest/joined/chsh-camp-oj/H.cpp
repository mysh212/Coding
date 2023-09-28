// Author : ysh
// 2023/07/07 Fri 14:52:44
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    while(c--) {
        int d;cin>>d;
        q.emplace(0,d - 1);
    }
    vector<vector<int>>f(a);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    vector<int>ans(a);
    vector<bool>mark(a);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        ans.at(d) = l;
        for(int &i : f.at(d)) {
            q.emplace(l + 1,i);
        }
    }

    cout<<*max_element(ans.begin(),ans.end());
    return 0;
}