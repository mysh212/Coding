// Author : ysh
// 10/07/2022 Fri  9:52:46.16
// https://judge.tcirc.tw/ShowProblem?problemid=d099
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>f;
vector<int>t;
vector<int>g;
vector<bool>mark;
int ans = 0;
inline void up(int a,int b) {
    if(t.at(a) == -1) {
        t.at(a) = b;
        return;
    }
    if(t.at(a) > b) {
        t.at(a) = b;
    }
    ans++;
    return;
}
int check(int x) {
    if(mark.at(x)) return 0;
    mark.at(x) = 1;
    for(int i : f.at(x)) {
        check(i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    g.resize(a);
    f.resize(a);
    t.resize(a,-1);
    mark.resize(a);
    for(int i = 0;i<a;i++) {
        cin>>g.at(i);
    }
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
    }
}