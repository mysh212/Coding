// Author : ysh
// 2023/09/06 Wed 16:43:05
// https://codeforces.com/contest/802/problem/A
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    vector<int>mark(a,INT_MAX),pre(a);
    for(int &i : f) {
        cin>>i;
        i--;
    }
    for(int i = a - 1;i>=0;i--) {
        pre.at(i) = mark.at(f.at(i));
        mark.at(f.at(i)) = i;
    }

    int ans,now;ans = now = 0;
    vector<bool>mk(a);
    priority_queue<pair<int,int>>q;

    for(int i = 0;i<a;i++) {
        if(i != 0) q.emplace(pre.at(i - 1),f.at(i - 1));
        if(mk.at(f.at(i))) continue;
        if(now < b) {
            mk.at(f.at(i)) = 1;
            now++;
            ans++;
            continue;
        }
        auto now = q.top();q.pop();
        while((!q.empty()) && (now.first < i || !mk.at(now.second))) {
            now = q.top();
            q.pop();
        }
        mk.at(now.second) = 0;
        mk.at(f.at(i)) = 1;
        ans++;
    }
    cout<<ans;
    return 0;
}