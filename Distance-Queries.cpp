// Author : ysh
// 10/27/2022 Thu  9:05:25.27
// https://cses.fi/problemset/task/1135
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<vector<int>>f;
vector<int>level;
vector<int>line;
vector<pair<int,int>>mk;
map<int,int>m;
#include<table>
int t = 0;
inline void check(int last,int d,int x) {
    m.insert({x,t++});
    int now = t - 1;
    level.at(now) = d;
    line.push_back(now);
    mk.at(now).first = line.size() - 1;
    for(int &i : f.at(x)) {
        if(i != last) {
            check(x,d + 1,i);
            line.push_back(now);
        }
    }
    mk.at(now).second = line.size() - 1;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    level.resize(a);
    mk.resize(a);
    int root = 0;
    {
    // vector<bool>in(a);
    for(int i = 0;i<a - 1;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
        // in.at(b) = 1;
    }
    // debug(in);
    // for(int i = 0;i<a;i++) {
    //     debug((int) in.at(i));
    //     if(!in.at(i)) {
    //         root = i;
    //         break;
    //     }
    // }
    }
    // debug(root);
    check(-1,0,0);
    // debug(level);
    for(auto &i : m) {
        cerr<<i.first + 1<<" "<<i.second<<" "<<level.at(i.second)<<"\n";
    }
    debug(line);
    table<int> t(line);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        a = m.find(a)->second;
        b = m.find(b)->second;
        int l = mk.at(a).second;
        int r = mk.at(b).first;
        if(l > r) swap(l,r);
        debug(a,b,l,r,t.get(l,r));
        cout<<level.at(a) + level.at(b) - (level.at(t.get(l,r)) << 1)<<"\n";
    }
    return 0;
}