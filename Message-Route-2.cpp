// Author : ysh
// 2023/07/12 Wed 16:15:51
// https://cses.fi/problemset/task/1667
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    queue<int>q;
    q.push(0);
    vector<int>re(a,-1);
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int &i : f.at(now)) {
            if(re.at(i) != -1) continue;
            re.at(i) = now;
            q.push(i);
        }
    }

    if(re.at(a - 1) == -1) return cout<<"IMPOSSIBLE",0;

    int d = a - 1;
    vector<int>ans({d});
    while(d != 0) {
        d = re.at(d);
        ans.push_back(d);
    }
    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<"\n";
    for(int &i : ans) cout<<i + 1<<" ";
    return 0;
}