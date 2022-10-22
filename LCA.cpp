// Author : ysh
// 10/15/2022 Sat  8:08:49.90
// https://www.luogu.com.cn/problem/P3379
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#include<table>
#include<bits/extc++.h>
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    c--;
    vector<vector<int>>f(a);
    for(int i = 0,len = a - 1;i<len;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    gp_hash_table<int,int>m,mr;
    vector<int>mk(a);
    vector<int>vtd;
    int r = 0;
    function<void()> check = [&] () {
        vector<bool>mark(a);
        queue<int>q;
        q.emplace(c);
        while(!q.empty()) {
            int now = q.front();q.pop();
            if(mark.at(now)) continue;
            mark.at(now) = 1;
            m.insert({++r,now});
            mr.insert({now,r});
            for(int &i : f.at(now)) {
                q.emplace(i);
            }
        }
        return;
    };
    vector<bool>mark(a);
    function<void(int)> ck = [&] (int x) {
        if(mark.at(x)) return;
        mark.at(x) = 1;
        int nr = mr.find(x)->second;
        vtd.push_back(nr);
        mk.at(x) = vtd.size() - 1;
        for(int &i : f.at(x)) {
            ck(i);
            vtd.push_back(nr);
        }
        return;
    };
    check();
    ck(c);
    table<int> t(vtd);
    debug(vtd);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<m.find(t.get(mk.at(a),mk.at(b)))->second + 1<<"\n";
    }
    return 0;
}