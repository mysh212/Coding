// Author : ysh
// 04/09/2023 Sun 15:04:18.74
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#include<tree>
int n;
vector<int>v;
#define MAX 100000
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>re;
    int t = 0;
    for(int &i : f) {
        cin>>i;
        re.push({i,t++});
    }
    vector<int>tmp(a,1);
    tree<int>tr(f),tt(tmp);

    vector<vector<array<int,3>>>q(MAX + 1);
    vector<int>ans(b);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        q.at(c).push_back({a,b,i});
    }
    for(int i = 0;i<=MAX;i++) {
        sort(q.at(i).begin(),q.at(i).end());
    }
    for(int i = 0;i<=MAX;i++) {
        // debug(i,q.at(i));
        vector<int>tmp;
        while(!re.empty() && re.top().first <= i) tr.add(re.top().second,-re.top().first),tt.add(re.top().second,-1),(re.top().first == i ? tmp.push_back(re.top().second) : void()),re.pop();
        // reverse(tmp.begin(),tmp.end());
        if(tmp.size() >= 2) assert(tmp.at(0) < tmp.at(1));
        // debug(tmp);
        for(auto &j : q.at(i)) {
            auto equ = upper_bound(tmp.begin(),tmp.end(),j[1]) - lower_bound(tmp.begin(),tmp.end(),j[0]);
            debug(j,equ,tr.sum(j[0],j[1]));
            ans.at(j[2]) = (tr.sum(j[0],j[1]) + i * ((j[1] - j[0] + 1) - equ - tt.sum(j[0],j[1]))) << 1;
        }
    }
    for(int i : ans) cout<<i<<"\n";
    return 0;
}
