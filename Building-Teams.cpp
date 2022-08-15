// Author : ysh
// 08/13/2022 Sat 22:35:47.51
// https://cses.fi/problemset/task/1668
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f[a];
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        tmpa--;
        tmpb--;
        f[tmpa].push_back(tmpb);
        f[tmpb].push_back(tmpa);
    }
    vector<int>mark(a,-1);
    queue<pair<int,bool>>q;
    for(int i = 0;i<a;i++) {
        if(mark[i] != -1) continue;
        debug(mark);
        q.emplace(i,0);
        while(!q.empty()) {
            auto now = q.front();q.pop();
            int n = now.first;
            bool t = now.second;
            if(mark[n] == -1) {
                mark[n] = t;
            } else if(mark[n] != t) {
                cout<<"IMPOSSIBLE";
                return 0;
            } else {
                continue;
            }
            for(int i : f[n]) {
                q.emplace(i,!t);
            }
        }
    }
    for(int i : mark) {
        cout<<(i == -1 ? 1 : i + 1)<<" ";
    }
    return 0;
}