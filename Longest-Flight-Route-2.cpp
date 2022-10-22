// Author : ysh
// 10/12/2022 Wed 11:21:18.28
// https://cses.fi/problemset/task/1680/
#include<bits/stdc++.h>
using namespace std;
vector<int>c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>in(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        in.at(b)++;
    }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(in.at(i) == 0) q.push(i);
    }
    vector<long long>dt(a,(int) -1e11);
    vector<int>mark(a,-1);
    dt.at(0) = 0;
    while(!q.empty()) {
        int now = q.front();q.pop();
        int j = now;
        for(int k : f.at(j)) {
            if(dt.at(j) + 1LL > dt.at(k)) {
                dt.at(k) = dt.at(j) + 1;
                mark.at(k) = j;
            }
        }
        for(int i : f.at(now)) {
            in.at(i)--;
            if(in.at(i) == 0) q.push(i);
        }
    }
    if(dt.at(a - 1) < 0) cout<<"IMPOSSIBLE";
    else {
        vector<int>ans;
        int now = a - 1;
        while(now != 0) {
            ans.push_back(now);
            now = mark.at(now);
        }
        cout<<ans.size() + 1;
        cout<<"\n1 ";
        while(!ans.empty()) {
            cout<<ans.back() + 1<<" ";ans.pop_back();
        }
    }
    return 0;
}