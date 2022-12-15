// Author : ysh
// 12/12/2022 Mon  9:58:21.90
// https://tioj.ck.tp.edu.tw/problems/2257
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,s,a,b;cin>>n>>s>>a>>b;
    s--;
    vector<vector<int>>f(n);
    map<pair<int,int>,int>pre;
    map<int,int>m;
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
        pre.insert({make_pair(a,b),i});
        pre.insert({make_pair(b,a),i});
    }
    // for(auto i : pre) cerr<<i.first.first<<" "<<i.first.second<<" "<<i.second<<"\n";
    vector<int>vtd;
    vector<pair<int,int>>v(n);
    vector<pair<int,int>>line(n);
    function<void(int,int,int)> check = [&] (int last,int x,int dt) {
        vtd.push_back(1);
        v.at(x).first = (vtd.size() - 1);
        auto found = pre.find(make_pair(last,x));
        // cerr<<found<<" ";
        if(last != -1) line.at(found->second).first = vtd.size() - 1;
        for(int &i : f.at(x)) {
            if(i != last) check(x,i,dt + 1);
        }
        vtd.push_back(-1);
        v.at(x).second = vtd.size() - 1;
        if(last != -1) line.at(found->second).second = vtd.size() - 1;
    };
    check(-1,s,0);
    // for(int &i : vtd) cerr<<i<<" ";
    // cerr<<"\n";
    // for(auto &i : v) {
    //     cerr<<i.first<<" ";
    // }
    // cerr<<"\n";
    // for(auto &i : v) {
    //     cerr<<i.second<<" ";
    // }
    // cerr<<"\n";
    tree<int>t(vtd);
    for(int i = 0,len = a + b;i<(len);i++) {
        int r;cin>>r;
        if(r == 1) {
            int m,r;cin>>m>>r;
            cout<<(t.sum(v.at(r - 1).first) - 1) * m<<"\n";
        }
        if(r == 2) {
            int r;cin>>r;
            t.add(line.at(r).first,-1);
            t.add(line.at(r).second,1);
        }
    }
}