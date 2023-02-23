// Author : ysh
// 02/22/2023 Wed 16:49:24.17
// https://cses.fi/problemset/task/1139/
#include<bits/stdc++.h>
using namespace std;
#include<tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    vector<vector<int>>v(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        v.at(a).push_back(b);
        v.at(b).push_back(a);
    }
 
    vector<pair<int,int>>subtree(n);
    vector<int>walk;
    function<void(int,int)> check = [&] (int last,int x) {
        subtree.at(x).first = walk.size();
        for(int &i : v.at(x)) {
            if(i == last) continue;
            check(x,i);
        }
        subtree.at(x).second = walk.size();
        walk.push_back(x);
        return;
    };
 
    check(0,0);
    map<int,int>last;
    tree<int>t(n);
    vector<int>ans(n);
    for(int i = 0;i<n;i++) {
        if(last.find(f.at(walk.at(i))) != last.end())  {
            t.add(last.find(f.at(walk.at(i)))->second,-1);
        }
        last[f.at(walk.at(i))] = i;
        t.add(i,1);
        ans.at(walk.at(i)) = t.sum(subtree.at(walk.at(i)).first,subtree.at(walk.at(i)).second);
    }
    for(int &i : ans) cout<<i<<" ";
    return 0;
}