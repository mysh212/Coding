// Author : ysh
// 2023/07/13 Thu 09:37:40
// https://codeforces.com/contest/14/problem/D
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>f;
pair<int,int> check(int last,int x) {
    int ans = 0;
    vector<int>pre;
    for(int &i : f.at(x)) {
        if(i == last) continue;
        auto d = check(x,i);
        ans = max(ans,d.second);
        pre.push_back(d.first);
    }
    sort(pre.rbegin(),pre.rend());
    if(pre.empty()) return make_pair(1,1);
    if(pre.size() == 1) return make_pair(pre.front() + 1,max(ans,pre.front() + 1));
    return make_pair(pre.at(0) + 1,max(ans,pre.at(0) + pre.at(1) + 1));
}
#define eo(i) (i) // (cerr<<#i<<":"<<i<<"\n",i)
int ck() {
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int &j : f.at(i)) {
            ans = max(ans,eo(check(eo(i),eo(j)).second - 1) * eo(check(j,i).second - 1));
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    f = vector<vector<int>>(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    cout<<ck();
    return 0;
}