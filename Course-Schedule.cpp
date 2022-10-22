// Author : ysh
// 10/11/2022 Tue 11:29:32.41
// https://cses.fi/problemset/task/1679
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int to[a] = {};
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        to[b]++;
    }
    queue<int>ans;
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front();q.pop();
        ans.push(now);
        for(int &i : f.at(now)) {
            to[i]--;
            if(to[i] == 0) {
                q.push(i);
            }
        }
    }
    if(ans.size() == a) {
        while(!ans.empty()) {
            cout<<ans.front() + 1<<" ";ans.pop();
        }
        return 0;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}