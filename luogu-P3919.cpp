// Author : ysh
// 02/03/2023 Fri 11:27:54.40
// https://www.luogu.com.cn/problem/P3919
#include<bits/stdc++.h>
using namespace std;
#define int long long
#include<fast>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    vector<vector<array<int,3>>>v(b + 1);
    vector<map<int,int>>q(b + 1);
    vector<pair<int,int>>todo;

    function<void(int,vector<int>&)> check = [&] (int ver,vector<int>&f) {
        for(auto &i : q.at(ver)) {
            i.second = f.at(i.first);
        }
        for(auto &j : v.at(ver)) {
            if(j[1] != -1) swap(f.at(j[1]),j[2]);
            check(j[0],f);
            if(j[1] != -1) swap(f.at(j[1]),j[2]);
        }
        return;
    };

    for(int &i : f) cin>>i;
    for(int i = 1;i<=b;i++) {
        int a,b;cin>>a>>b;
        if(b == 1) {
            int c,d;cin>>c>>d;
            v.at(a).push_back({i,c - 1,d});
        } else {
            int c;cin>>c;
            q.at(a).insert({c - 1,0});
            todo.push_back({a,c - 1});
            v.at(a).push_back({i,-1,0});
        }
    }
    check(0,f);
    for(auto &i : todo) {
        cout<<q[i.first][i.second]<<"\n";
    }
    return 0;
}