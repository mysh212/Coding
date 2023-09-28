// Author : ysh
// 2023/07/20 Thu 16:45:11
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#include<fast>
#define yes "<(_ _)>\n"
#define no ">_<\n"
#define att(i) (color.at(i.first).at(i.second))
int a,b,c;
struct mgbox{
    vector<vector<pair<int,int>>>color;
    // vector<vector<bool>>v;
    int a,b;
    const int xx[4] = {-1,0,1,0};
    const int yy[4] = {0,1,0,-1};

    mgbox() {
        return;
    }

    mgbox(vector<vector<bool>>&v) {
        a = v.size();
        b = v.at(0).size();
        // this->v = v;
        color = vector<vector<pair<int,int>>>(a,vector<pair<int,int>>(b,{-1,-1}));
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                if(i != 0 && !v[i][j] && !v[i - 1][j]) mg({i,j},{i - 1,j});
                if(j != 0 && !v[i][j] && !v[i][j - 1]) mg({i,j},{i,j - 1});
            }
        }
        return;
    }

    mgbox(mgbox &a) {
        this->a = a.a;
        this->b = a.b;
        color = a.color;
        // v = a.v;
        return;
    }

    void operator=(mgbox a) {
        this->a = a.a;
        this->b = a.b;
        color = a.color;
        // v = a.v;
        return;
    }

    pair<int,int> ff(pair<int,int>x) {
        if(att(x) == x || att(x) == make_pair(-1,-1)) return x;
        return att(x) = ff(att(x));
    }

    void mg(pair<int,int>a,pair<int,int>b) {
        att(ff(a)) = ff(b);
        return;
    }

    bool check() {
        set<pair<int,int>>s;
        for(int i = 0;i<a;i++) {
            s.insert(ff({i,0}));
        }
        for(int i = 0;i<a;i++) {
            if(s.count(ff({i,b - 1}))) return 1;
        }
        return 0;
    }

    void pc() {
        map<pair<int,int>,int>m;
        int t = 0;
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                if(m.find(ff({i,j})) == m.end()) m.insert({ff({i,j}),++t});
                cerr<<m[ff({i,j})]<<" ";
            }
            cerr<<"\n";
        }
        cerr<<"\n";
        return;
    }
}mb;
bool check(vector<pair<int,int>>&f,int x,mgbox &t) {
    mgbox tmp(t);
    for(int i = x + 1;i<c;i++) {
        if(f[i] == make_pair(-1,-1)) continue;
        int x = f[i].first;
        int y = f[i].second;
        if(x != 0) tmp.mg({x,y},{x - 1,y});
        if(y != 0) tmp.mg({x,y},{x,y - 1});
        if(x != a - 1) tmp.mg({x,y},{x + 1,y});
        if(y != b - 1) tmp.mg({x,y},{x,y + 1});
    }
    debug(x);
    // tmp.pc();
    return tmp.check();
}
int ck(vector<pair<int,int>>&pre,int l,int r,mgbox &t) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(pre,mid,t)) return ck(pre,mid,r,t);
    else return ck(pre,l,mid,t);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    vector<vector<bool>>f(a,vector<bool>(b));
    vector<pair<int,int>>pre(c);
    vector<bool>ans(c,1);
    for(auto &i : pre) {
        cin>>i.first>>i.second;
        f.at(i.first).at(i.second) = 1;
    }
    
    mgbox t(f);
    int now = ck(pre,-1,c,t);
    while(now != c - 1) {
        int x = pre.at(now + 1).first;
        int y = pre.at(now + 1).second;
        debug(now,x,y);
        if(x != 0 && (!f[x - 1][y])) t.mg({x,y},{x - 1,y});
        if(y != 0 && (!f[x][y - 1])) t.mg({x,y},{x,y - 1});
        if(x != a - 1 && (!f[x + 1][y])) t.mg({x,y},{x + 1,y});
        if(y != b - 1 && (!f[x][y + 1])) t.mg({x,y},{x,y + 1});
        // t.pc();
        f[x][y] = 0;
        pre.at(now + 1) = {-1,-1};
        ans.at(now + 1) = 0;
        now = ck(pre,now + 1,c,t);
    }

    for(bool i : ans) {
        if(i) cout<<yes;
        else cout<<no;
    }
    return 0;
}