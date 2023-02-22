// Author : ysh
// 02/22/2023 Wed 11:37:02.09
// https://cses.fi/problemset/task/1139/
#include<bits/stdc++.h>
using namespace std;
void offline(vector<int>&f) {
    map<int,int>m;
    for(int &i : f) {
        m.insert({i,0});
    }
    int t = 0;
    for(auto &i : m) {
        i.second = t++;
    }
    for(int &i : f) {
        i = m.find(i)->second;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    // offline(f);
    vector<vector<int>>v(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        v.at(a).push_back(b);
        v.at(b).push_back(a);
    }

    vector<int>ans(n);
    function<set<int>(int,int)> check = [&] (int last,int x) {
        set<int>now;
        for(int &i : v.at(x)) {
            if(i == last) continue;
            set<int>s(check(x,i));
            if(now.size() < s.size()) {
                s.swap(now);
            }
            for(int i : s) now.insert(i);
        }
        now.insert(f.at(x));
        ans.at(x) = now.size();
        return now;
    };

    check(-1,0);
    for(int &i : ans) cout<<i<<" ";
    return 0;
}