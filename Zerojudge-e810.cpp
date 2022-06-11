// Author : ysh
// 05/27/2022 Fri 16:51:29.58
#include<bits/stdc++.h>
using namespace std;
vector<int>c;
void cc(int,int);
inline int ff(int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    c.resize(a);
    iota(c.begin(),c.end(),0);
    vector<pair<int,pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        f[i] = {cc,{aa,bb}};
    }
    sort(f.rbegin(),f.rend());
    int n = a - 1;
    vector<pair<int,int>>s[a];
    while(!f.empty() && n != 0) {
        auto now = f.back();f.pop_back();
        int x = now.second.first;
        int y = now.second.second;
        if(ff(x) == ff(y)) {
            continue;
        }
        n--;
        s[x].push_back({y,now.first});
        s[y].push_back({x,now.first});
        cc(x,y);
    }
    int aa,bb;cin>>aa>>bb;
    queue<pair<int,int>>q;
    q.push({0,aa});
    c.clear();
    c.resize(a,0);
    for(int i : c) cout<<i;
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int v = now.first;
        int t = now.second;
        for(auto i : s[t]) {
            // cout<<1;
            if(c[i.first] != 0) {
                continue;
            }
            c[i.first] = v + i.second;
            q.push({i.first,v + i.second});
            if(i.first == bb) {
                cout<<v + i.second;
                return 0;
            }
        }
    }
    return -1;
}
void cc(int a,int b) {
    c[ff(a)] = c[ff(b)];
    return;
}
inline int ff(int x) {
    if(c[x] == x) return x;
    return c[x] = ff(c[x]);
}