// Author : ysh
// 01/08/2023 Sun  9:59:52.18
// https://judge.tcirc.tw/ShowProblem?problemid=d099
// NF
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>g(a + 1);
    for(int i = 1;i<=a;i++) {
        cin>>g[i];
    }
    vector<vector<int>>f(a + 1);
    for(int i = 1;i<=a;i++) {
        f.at(0).push_back(i);
    }
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        f.at(a).push_back(b);
    }
    function<int(int,int,int)> check = [&] (int last,int x,int now) {
        now = now + g.at(x);
        int mmax = now;
        for(int &i : f.at(x)) {
            mmax = max(mmax,check(x,i,now));
        }
        return mmax;
    };
    cout<<check(-1,0,0);
    return 0;
}