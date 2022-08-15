// Author : ysh
// 08/13/2022 Sat 10:08:29.02
// https://cses.fi/problemset/task/1667
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
        tmpa--;tmpb--;
        f[tmpa].push_back(tmpb);
        f[tmpb].push_back(tmpa);
    }
    queue<pair<int,int>>q;
    q.emplace(0,0);
    vector<int>mark(a,-1);
    // mark[0] = 1;
    bool c = 0;
    while(!q.empty()) {
        auto now = q.front();q.pop();
        debug(now);
        int n = now.first;
        int t = now.second;
        if(n == a - 1) {
            c = 1;
            break;
        }
        // if(mark[n]) continue;
        // mark[n] = 1;
        for(int i : f[n]) {
            if(mark[i] != -1) continue;
            q.emplace(i,t + 1);
            mark[i] = n;
        }
    }
    if(!c) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int>p;
    int r = a - 1;
    while(r != 0) {
        p.push_back(r);
        r = mark[r];
    } 
    p.push_back(0);
    cout<<p.size()<<"\n";
    while(!p.empty()) {
        cout<<p.back() + 1<<" ";p.pop_back();
    }
    return 0;
}