// Author : ysh
// 11/18/2022 Fri 10:11:54.30
// https://cses.fi/problemset/task/1688/
#include<bits/stdc++.h>
using namespace std;
struct ntree{
    vector<vector<int>>f;
    vector<vector<int>>v;
    vector<int>level;
    int n,g;

    ntree(vector<vector<int>>&v):
        f(v), n(v.size()), g(__lg(v.size()) + 1) {
            this->v.resize(v.size(),vector<int>(g));
            level.resize(v.size());
        };
    
    void init(int last,int x) {
        v[x][0] = last;
        level.at(x) = level.at(last) + 1;
        for(int i = 1;i<g;i++) {
            v[x][i] = v[v[x][i - 1]][i - 1];
        }
        // cerr<<x;
        for(int &i : f.at(x)) {
            if(i != last) init(x,i);
        }
    }

    int check(int a,int b) {
        if(level.at(a) > level.at(b)) swap(a,b);
        int jump = level.at(b) - level.at(a);
        for(int i = 0;i < g;jump = jump >> 1,i++) {
            if(jump == 0) break;
            if(jump & 1) b = v[b][i];
        }
        // cerr<<g<<" ";
        // cerr<<level.at(a)<<" "<<level.at(b)<<"\n";
        if(a == b) return a;
        // assert(level.at(a) == level.at(b));
        for(int i = g - 1;i >= 0;i--) {
            if(v[a][i] != v[b][i]) {
                a = v[a][i];
                b = v[b][i];
            }
        }
        return v[a][0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    // for(int i = 1;i<a;i++) {
    //     f.at(0).push_back(i);
    // }
    for(int i = 1;i<a;i++) {
        int tmp;cin>>tmp;
        tmp--;
        f.at(tmp).push_back(i);
    }
    ntree t(f);
    t.init(0,0);
    while(b--) {
        int a,b;cin>>a>>b;
        cout<<t.check(a - 1,b - 1) + 1<<"\n";
    }
    return 0;
}