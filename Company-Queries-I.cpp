// Author : ysh
// 11/04/2022 Fri 14:03:57.46
// https://cses.fi/problemset/task/1687
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>mark;
vector<int>level;
int n,g;
void ck(int,int,vector<vector<int>>&);
void init(vector<vector<int>>&f) {
    ck(0,0,f);
    return;
}
void ck(int last,int x,vector<vector<int>>&f) {
    level.at(x) = level.at(last) + 1;
    mark.at(x).at(0) = last;
    for(int i = 1;i<=g;i++) {
        mark.at(x).at(i)  = mark.at(mark.at(x).at(i - 1)).at(i - 1);
    }
    for(int &i : f.at(x)) {
        ck(x,i,f);
    }
    return;
}
int check(int x,int r) {
    if(r >= level.at(x)) return -2;
    for(int i = 0;i <= g;i++,r = r >> 1) {
        if(r & 1) x = mark.at(x).at(i);
        if(r == 0) break;
    }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    n = a;g = __lg(a);
    mark.resize(n,vector<int>(g + 1));
    level.resize(a);
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int tmp;cin>>tmp;
        f.at(tmp - 1).push_back(i);
    }
    init(f);
    // for(auto &i : level) {
    //     cerr<<i<<" ";
    // }
    // cerr<<"\n";
    while(b--) {
        int a,b;cin>>a>>b;
        a--;
        cout<<check(a,b) + 1<<"\n";
    }
    return 0;
}