// Author : ysh
// 12/08/2022 Thu  9:11:52.25
// https://codeforces.com/contest/1696/problem/D
#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>v(n);
        for(int &i : v) {
            cin>>i;
            i--;
        }
        vector<vector<int>>f(n);
        for(int i = 0;i<n;i++) {
            int mmin = v.at(i);
            int mmax = v.at(i);
            for(int j = i + 1;j < n;j++) {
                mmin = min(v.at(j),mmin);
                mmax = max(mmax,v.at(j));
                if(mmin == min(v.at(i),v.at(j)) && mmax == max(v.at(i),v.at(j))) {
                    f.at(i).push_back(j);
                    f.at(j).push_back(i);
                }
            }
        }
        vector<bool>mark(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,0);
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;
            if(d == n - 1) {
                cout<<l<<"\n";
                break;
            }
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            for(int &i : f.at(d)) {
                q.emplace(l + 1,i);
            }
        }
    }
    return 0;
}