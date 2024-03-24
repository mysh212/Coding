// Author : ysh
// 2024/01/24 Wed 21:30:03
// BP
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#include<fast>
#define int int64_t
vector<vector<pair<int,int>>>f,g;
vector<vector<int>>mark,mmax;
vector<int>color,level;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
inline void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
}
void init(vector<vector<pair<int,int>>>&f) {
    // re(i,f.size()) {outs(i); repo(&j,f.at(i)) outs(j); nl;};
    // exit(2);

    int n = f.size();
    int g = __lg(n);
    queue<pair<int,int>>q;
    q.emplace(0,0);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;
        // cerr<<x<<"\n";

        level.at(x) = level.at(last) + 1;
        mark.at(x).at(0) = last;

        // cerr<<1;
        for(int i = 1;i<=g;i++) {
            mark.at(x).at(i) = mark.at(mark.at(x).at(i - 1)).at(i - 1);
            mmax.at(x).at(i) = max(mmax.at(x).at(i - 1),mmax.at(mark.at(x).at(i - 1)).at(i - 1));
        }

        // cerr<<2;
        for(auto &i : f.at(x)) {
            if(i.first == last) continue;
            mmax.at(i.first).at(0) = i.second;
            q.emplace(x,i.first);
        }
    }
    return;
}
pair<int,int> check(int a,int b) {
    int n = f.size();
    int g = __lg(n);
    if(level.at(a) > level.at(b)) swap(a,b);
    int ans = 0;
    for(int i = g;i>=0;i--) {
        if(level.at(mark.at(b).at(i)) >= level.at(a)) ans = max(ans,mmax.at(b).at(i)),b = mark.at(b).at(i);
    }

    if(a == b) return make_pair(a,ans);
    for(int j = g;j>=0;j--) {
        if(mark.at(a).at(j) == mark.at(b).at(j)) continue;

        ans = max(ans,mmax.at(a).at(j));
        ans = max(ans,mmax.at(b).at(j));
        a = mark.at(a).at(j);
        b = mark.at(b).at(j);
    }

    return make_pair(mark.at(a).at(0), max({ans,mmax.at(a).at(0),mmax.at(b).at(0)}));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;

    int64_t ans = 0;
    vc<array<int,3>>v;
    color = vc<int>(a);
    iota(all(color),0);
    f.resize(a);
    g.resize(a);
    mark = mmax = vc<vc<int>>(a,vc<int>(__lg(a) + 1));
    level.resize(a,-1);

    re(b) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        v.push_back({a,b,c});
    }

    sort(all(v),[](array<int,3>&a,array<int,3>&b) {
        return a[2] < b[2];
    });

    repo(&i,v) {
        if(ff(i[0]) == ff(i[1])) {
            g.at(i[0]).push_back({i[1],i[2]});
            g.at(i[1]).push_back({i[0],i[2]});
            continue;
        }
        f.at(i[0]).push_back({i[1],i[2]});
        f.at(i[1]).push_back({i[0],i[2]});

        mg(i[0],i[1]);
        ans += i[2];
    }

    init(f);

    int64_t mmin = LLONG_MAX;
    re(i,a) repo(&j,g.at(i)) {
        mmin = min(ans - check(i,j.first).second + j.second,mmin);
    }

    cout<<ans<<" "<<mmin;
    return 0;
}