// Author : ysh
// 10/25/2022 Tue 10:48:10.14
#include<bits/stdc++.h>
using namespace std;
// #define int long long
vector<int>v;
vector<vector<pair<int,int>>>f;
// #include<table>
struct box{
    int x,y,z;
    box(int x = 0,int y = 0,int z = 0):
        x(x), y(y), z(z) {};
    inline bool operator<(const box a) const {
        return z > a.z;
    }
};
inline int ff(int x) {
    if(v.at(x) == x) return x;
    return v.at(x) = ff(v.at(x));
}
inline void mg(int a,int b) {
    v.at(ff(a)) = ff(b);
    return;
}
vector<bool>mark;
int mmax = 0;
bool walk(int x,int y) {
    if(mark.at(x)) return 0;
    mark.at(x) = 1;
    for(auto &i : f.at(x)) {
        if(i.first == y) {
            mmax = i.second;
            mark.at(x) = 0;
            return 1;
        }
        if(walk(i.first,y)) {
            mmax = max(mmax,i.second);
            mark.at(x) = 0;
            return 1;
        }
    }
    mark.at(x) = 0;
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    v.resize(a);
    f.resize(a);
    mark.resize(a);
    iota(v.begin(),v.end(),0);
    priority_queue<box>q;
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        // f.at(a).push_back({b,c});
        // f.at(b).push_back({a,c});
        q.push(box(a,b,c));
    }
    int line = a - 1;
    long long ans = 0;
    queue<box>p;
    while(!q.empty()) {
        if(line == 0) break;
        auto now = q.top();q.pop();
        if(ff(now.x) != ff(now.y)) {
            f.at(now.x).push_back({now.y,now.z});
            f.at(now.y).push_back({now.x,now.z});
            mg(now.x,now.y);
            ans += now.z;
            line--;
            continue;
        }
        p.push(now);
    }
    long long mmin = LONG_LONG_MAX;
    while(!q.empty()) p.push(q.top()),q.pop();
    while(!p.empty()) {
        auto now = p.front();p.pop();
        walk(now.x,now.y);
        // cerr<<now.x + 1<<" "<<now.y + 1<<" "<<now.z<<" "<<mmax<<"\n";
        mmin = min(ans + now.z - mmax,mmin);
    }
    cout<<ans<<" "<<mmin;
    return 0;
}