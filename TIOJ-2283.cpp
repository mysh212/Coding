// Author : ysh
// 11/09/2022 Wed 11:23:22.04
// https://tioj.ck.tp.edu.tw/problems/2283
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a),group(b);
    vector<int>v(b),dt(a,(long long) 2e14);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        v.at(i) = b;
        for(int j = 0;j<a;j++) {
            int tmp;cin>>tmp;
            tmp--;
            group.at(i).push_back(tmp);
            f.at(tmp).push_back(i);
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    dt.at(0) = 0;
    vector<bool>mark(a);
    vector<bool>mk(b);
    int mmax = 0;
    int r = a;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.first;
        int d = now.second;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        mmax = max(l,mmax);
        r--;
        for(int &i : f.at(d)) {
            if(mk.at(i)) continue;
            mk.at(i) = 1;
            for(int &j : group.at(i)) {
                if(d == j) continue;
                if(!mark.at(j) && dt.at(j) > dt.at(d) + v.at(i)) {
                    dt.at(j) = dt.at(d) + v.at(i);
                    q.push({dt.at(j),j});
                }
            }
        }
    }
    // for(int &i : dt) cerr<<i<<" ";
    // int mmax = *max_element(dt.begin(),dt.end());
    cout<<((mmax == 2e14 || r != 0) ? -1 : mmax);
    return 0;
}