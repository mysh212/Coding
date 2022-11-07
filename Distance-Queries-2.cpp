// Author : ysh
// 11/04/2022 Fri 14:31:53.56
// https://cses.fi/problemset/task/1135
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>mark;
vector<int>level;
int n,g;
void ck(int,int,vector<vector<int>>&);
void init(vector<vector<int>>&f) {
    mark.resize(n,vector<int>(g + 1));
    level.resize(n);
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
        if(i != last) ck(x,i,f);
    }
    return;
}
int check(int a,int b) {
    if(level.at(a) > level.at(b)) swap(a,b);
    int jump = level.at(b) - level.at(a);
    for(int i = 0;i<=g;i++,jump = jump >> 1) {
        if(jump == 0) break;
        if(jump & 1) b = mark.at(b).at(i);
    }
    if(a == b) return a;
    for(int i = g;i >= 0;i--) {
        if(mark.at(a).at(i) == mark.at(b).at(i)) continue;
        a = mark.at(a).at(i);
        b = mark.at(b).at(i);
    }
    return mark.at(a).at(0);
}
inline int dt(int a,int b) {
    return level.at(a) + level.at(b) - (level.at(check(a,b)) << 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    n = a;g = __lg(a);
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    init(f);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<dt(a,b)<<"\n";
    }
    return 0;
}