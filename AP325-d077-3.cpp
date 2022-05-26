// Author : ysh
// 04/27/2022 Wed 12:03:11.65
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    vector<int>c(a);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        pair<int,int> now = {0,0};
        while(!q.empty()) {
            now = q.top();
            if(now.first == 0 && now.second == 0 && i >= b + 1) q.pop();
            if(now.second >= i - b - b - 1) break;
            q.pop();
        }
        c[i] = now.first + f[i];
        q.push({c[i],i});
        // if(i == 2) {
        //     while(!q.empty()) {
        //         cout<<q.top().first<<" "<<q.top().second<<"\n";q.pop();
        //     }
        //     return 0;
        // }
    }
    // for(int i : c) cout<<i<<" ";
    // cout<<"\n";
    cout<<*min_element(c.end() - 1 - b,c.end());
    return 0;
}