// Author : ysh
// 10/16/2022 Sun 17:14:59.00
// https://cses.fi/problemset/task/1132
#include<bits/stdc++.h>
using namespace std;
vector<bool>mark;
vector<vector<int>>dt;
vector<vector<int>>f;
int mmax = 0;
int d = 0;
void check(int x,int now,int l) {
    if(mark.at(x)) return;
    mark.at(x) = 1;
    dt.at(now).at(x) = l;
    // cerr<<1;
    if(l > mmax) {
        mmax = l;
        d = x;
    }
    for(int &i : f.at(x)) {
        check(i,now,l + 1);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    f.resize(a);
    dt.resize(2,vector<int>(a));
    mark.resize(a);
    for(int i = 0;i<a - 1;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    check(0,0,0);
    mmax = 0;
    mark = vector<bool>(a);
    check(d,0,0);
    mmax = 0;
    mark = vector<bool>(a);
    check(d,1,0);
    for(int i = 0;i<a;i++) {
        cout<<max(dt[0][i],dt[1][i])<<" ";
    }
    return 0;
}