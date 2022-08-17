// Author : ysh
// 08/16/2022 Tue 16:09:44.85
// https://cses.fi/problemset/task/1671
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int l,d;
    box(int a = 0,int b = 0):
        l(b), d(a) {};
    bool operator<(const box a) const {
        return l > a.l;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f[a];
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f[a].push_back(box(b,c));
        // f[b].push_back(box(a,c));
    }
    vector<int>ans(a,-1);
    // vector<bool>mark(a);
    priority_queue<box>q;
    q.push(box(0,0));
    while(!q.empty()) {
        box now = q.top();q.pop();
        int d = now.d;
        int l = now.l;
        if(ans[d] != -1) continue;
        ans[d] = l;
        for(box i : f[d]) {
            int nd = i.d;
            int nl = i.l;
            q.push(box(nd,l + nl));
        }
    }
    for(int i : ans) {
        cout<<i<<" ";
    }
    return 0;
}