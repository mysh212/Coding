// Author : ysh
// 01/06/2023 Fri  9:53:54.37
// https://open.kattis.com/problems/increasingsubsequence
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        if(n == 0) break;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
        }
        vector<pair<int,int>>g;
        vector<int>mark(n,-1);
        for(int i = 0;i<n;i++) {
            int &now = f.at(i);
            auto found = lower_bound(g.begin(),g.end(),now,[] (pair<int,int>a,int b) {
                return a.first < b;
            });
            if(found == g.end()) {
                g.push_back({now,i});
                if(g.size() > 1) {
                    mark.at(i) = (g.at(g.size() - 2).second);
                }
            } else {
                *found = {now,i};
                if(found != g.begin()) {
                    mark.at(i) = prev(found)->second;
                }
            }
            // for(auto &i : g) cerr<<i.first<<" ";
            // cerr<<"\n";
        }
        // for(int &i : mark) cerr<<i<<" ";
        // cerr<<"\n";
        cout<<g.size()<<" ";
        int now = g.back().second;
        vector<int>ans;
        while(now != -1) {
            ans.push_back(f.at(now));
            now = mark.at(now);
        }
        while(!ans.empty()) {
            cout<<ans.back()<<" ";
            ans.pop_back();
        }
        cout<<"\n";
    }
    return 0;
}