// Author : ysh
// 09/16/2022 Fri 22:31:59.27
// https://judge.tcirc.tw/ShowProblem?problemid=c085
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
inline int ff(int x) {
    if(f.at(x) == x) return x;
    return f.at(x) = ff(f.at(x));
}
void mg(int a,int b) {
    f.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    iota(f.begin(),f.end(),0);
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        mg(tmpa,tmpb);
    }
    vector<int>mark(a);
    vector<pair<int,int>>r(a);
    for(int i : f) {
        mark.at(ff(i))++;
    }
    for(int i = 0;i<a;i++) {
        r.at(i) = {mark.at(ff(i)),i};
    }
    sort(r.begin(),r.end(),[] (pair<int,int>a,pair<int,int>b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    for(auto i : r) {
        cout<<i.second<<" ";
    }
    cout<<"\n";
    return 0;
}