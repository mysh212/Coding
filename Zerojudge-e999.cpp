// Author : ysh
// 06/16/2023 Fri 20:52:01.71
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>in(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        f.at(a).push_back(b);
        in.at(b)++;
    }

    queue<int>q({0});
    vector<int>v(a);
    v.at(0) = 1;
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int &i : f.at(now)) {
            if(--in.at(i) == 0) q.push(i);
            v.at(i) += v.at(now);
        }
    }
    cout<<v.at(a - 1);
    return 0;
}