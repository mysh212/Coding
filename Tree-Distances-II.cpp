// Author : ysh
// 10/16/2022 Sun 17:30:29.90
// https://cses.fi/problemset/task/1133
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n);
    int root = 0;
    {
    vector<int>to(n);
    for(int i = 0;i<n - 1;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    for(int i = 0;i<n;i++) {
        if(to.at(i) == 0) root = i;
    }
    }
    vector<bool>mark(n);
    vector<int>dt(n);
    vector<pair<int,int>>mk(n);
    function<pair<int,int>(int,int)> check = [&] (int x,int l) {
        if(mark.at(x)) return make_pair(0,0);
        mark.at(x) = 1;
        int d = 0,sig = 0;
        for(int &i : f.at(x)) {
            auto now = check(i,l + 1);
            d += now.first;
            sig += now.second;
        }
        return mk.at(x) = make_pair(d + 1,sig + d + 1);
    };
}