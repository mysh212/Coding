// Author : ysh
// 02/23/2023 Thu 20:25:12.24
// https://cses.fi/problemset/task/1138
#include<bits/stdc++.h>
using namespace std;
#include<tree>
#define int long long
#include<fast>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f.at(i);
    }
    vector<vector<int>>v(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        v.at(a).push_back(b);
        v.at(b).push_back(a);
    }

    vector<pair<int,int>>re(a);
    vector<int>walk;
    function<void(int,int)> check = [&] (int last,int x) {
        re.at(x).first = walk.size();
        walk.push_back(f.at(x));
        for(int &i : v.at(x)) {
            if(i == last) continue;
            check(x,i);
        }
        re.at(x).second = walk.size();
        walk.push_back(-f.at(x));
        return;
    };

    check(0,0);
    tree<long long>t(walk);
    while(b--) {
        int a;cin>>a;
        if(a == 1) {
            int a,b;cin>>a>>b;
            a--;
            t.add(re.at(a).first,b - f.at(a));
            t.add(re.at(a).second,f.at(a) - b);
            f.at(a) = b;
        }
        if(a == 2) {
            int tmp;cin>>tmp;
            tmp--;
            cout<<t.sum(re.at(tmp).first)<<"\n";
        }
    }
    return 0;
}