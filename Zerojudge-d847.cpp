// Author : ysh
// 11/24/2022 Thu 22:36:10.71
#include<bits/stdc++.h>
using namespace std;
#include<tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        tree<int>t(1001);
        vector<pair<int,int>>f;
        for(int i = 0;i<n;i++) {
            int a,b;cin>>a>>b;
            f.push_back({a,b});
        }
        vector<pair<int,int>>g(f);
        map<pair<int,int>,int>m;
        sort(f.begin(),f.end());
        vector<int>todo;
        int last = 0;
        for(int i = 0;i<n;i++) {
            auto &now = f.at(i);
            if(now.first != last) {
                for(int &i : todo) t.add(i,1);
                todo.clear();
                last = now.first;
            }
            m.insert({now,t.sum(0,now.second - 1)});
            todo.push_back(now.second);
            // t.add(now.second,1);
        }
        for(auto &i : g) {
            cout<<m.find(i)->second<<"\n";
        }
    }
    return 0;
}