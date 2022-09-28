// Author : ysh
// 09/24/2022 Sat  8:40:30.45
// https://cses.fi/problemset/task/1132
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int rr = 0;
inline pair<int,int> ft(pair<int,int>&c,int a,int d) {
    int r[] = {c.first,c.second,a};
    sort(r,r+3);
    if(r[2] == a) rr = d;
    return c = {r[2],r[1]};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        f.at(a - 1).push_back(b - 1);
        f.at(b - 1).push_back(a - 1);
    }
    pair<int,int>mmax = {0,0};
    vector<bool>mark(n);
    vector<int>deep(n),fl(n);
    function<int(int,int)> check = [&] (int x,int d = 0) {
        if(mark.at(x)) return 0;
        mark.at(x) = 1;
        deep.at(x) = d;
        int r = 0;
        for(int i : f.at(x)) {
            r = max(r,check(i,d + 1));
        }
        fl.at(x) = r;
        return r + 1;
    };
    function<void(int)> pluz = [&] (int x) {
        if(mark.at(x)) return;
        mark.at(x) = 1;
        deep.at(x) += mmax.second;
        for(int i : f.at(x)) {
            pluz(i);
        }
        return;
    };
    for(int i = 0;i<n;i++) {
        ft(mmax,check(i,0),i);
    }
    debug(mmax);
    mark = vector<bool>(n);
    debug(deep);
    pluz(rr);
    debug(deep);
    for(int i = 0;i<n;i++) {
        if(!mark.at(i)) deep.at(i) += mmax.first;
    }
    debug(deep);
    debug(fl);
    // for(int &i : deep) {
    //     cout<<i<<" ";
    // }
    return 0;
}