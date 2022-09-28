// Author : ysh
// 09/23/2022 Fri 20:14:07.72
// https://cses.fi/problemset/task/1131
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>f;
vector<bool>mark;
inline pair<int,int> ft(pair<int,int> &c,int a) {
    int r[] = {c.first,c.second,a};
    sort(r,r + 3);
    return c = {r[2],r[1]};
}
pair<int,int> check(int n) {
    if(mark.at(n)) return {0,0};
    mark.at(n) = 1;
    bool c = 0;
    int nc = 0;
    pair<int,int> mmax = {0,0};
    for(int i : f.at(n)) {
        auto tmp = check(i);
        nc = max(nc,tmp.second);
        ft(mmax,tmp.first);
        c = 1;
    }
    if(!c) return make_pair(1,1);
    nc = max(nc,mmax.first + mmax.second + 1);
    return {mmax.first + 1,nc};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    mark.resize(n);
    bitset<200000>s;
    s.set();
    for(int i = 1;i < n;i++) {
        int a,b;cin>>a>>b;
        s.reset(b - 1);
        f.at(a - 1).push_back(b - 1);
        f.at(b - 1).push_back(a - 1);
    }
    cout<<check(s._Find_first()).second - 1;
    return 0;
}