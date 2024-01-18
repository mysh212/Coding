// Author : ysh
// 2024/01/18 Thu 16:31:34
// https://cses.fi/problemset/task/1135
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> init(vector<vector<int>>&f,int n) {
    vector<vector<int>>mark(n,vector<int>(__lg(n) + 1));
    queue<pair<int,int>>q;
    q.emplace(0,0);
    int g = __lg(n) + 1;
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;

        mark.at(x).at(0) = last;
        for(int i = 1;i<g;i++) {
            mark.at(x).at(i) = mark.at(mark.at(x).at(i - 1)).at(i - 1);
        }

        for(int &i : f.at(x)) if(i != last) q.emplace(x,i);
    }
    return mark;
}
int check(vector<vector<int>>&mark,vector<int>&level,int a,int b) {
    if(level.at(a) > level.at(b)) swap(a,b);
    int n = mark.size();
    int g = __lg(n) + 1;

    for(int i = g - 1;i>=0;i--) {
        if(level.at(mark.at(b).at(i)) >= level.at(a)) b = mark.at(b).at(i);
    }

    if(a == b) return a;
    for(int i = g - 1;i>=0;i--) {
        if(mark.at(a).at(i) != mark.at(b).at(i)) a = mark.at(a).at(i),b = mark.at(b).at(i);
    }
    return mark.at(a).at(0);
}
vector<int> ck(vector<vector<int>>&f,int n) {
    queue<pair<int,int>>q;
    q.emplace(0,0);
    vector<int>level(n,-1);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;

        level.at(x) = level.at(last) + 1;

        for(int &i : f.at(x)) if(i != last) q.emplace(x,i);
    }
    return level;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    auto mark = init(f,a);
    auto level = ck(f,a);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        int now = check(mark,level,a,b);
        cout<<(level.at(a) - level.at(now)) + (level.at(b) - level.at(now))<<"\n";
    }
    return 0;
}