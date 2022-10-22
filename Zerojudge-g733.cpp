// Author : ysh
// 10/03/2022 Mon 15:00:39.37
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<pair<int,int>>>f(a),g(a);
    for(int i = 0;i<b;i++) {
        int aa,bb,cc;cin>>aa>>bb>>cc;
        f.at(aa).push_back({bb,cc});
        f.at(bb).push_back({aa,cc});
    }
    for(int i = 0;i<c;i++) {
        int aa,bb,cc;cin>>aa>>bb>>cc;
        g.at(aa).push_back({bb,cc});
        g.at(bb).push_back({aa,cc});
    }
    int l,r;cin>>l>>r;
    int mmin = INT_MAX;
    for(int i = 0;i<=1;i++) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q,p;
        vector<bool>mark(a);
        q.push({0,l});
        while(!q.empty()) {
            auto now = q.top();q.pop();
            int l = now.first;
            int d = now.second;
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            if(d == r) {
                mmin = min(l,mmin);
                break;
            }
            for(pair<int,int> i : f.at(d)) {
                q.emplace(l + i.second,i.first);
                p.emplace(l + i.second,i.first);
            }
        }
        mark = vector<bool>(a);
        while(!p.empty()) {
            auto now = p.top();p.pop();
            int l = now.first;
            int d = now.second;
            if(mark.at(d)) continue;
            mark.at(d) = 1;
            if(d == r) {
                mmin = min(l,mmin);
            }
            for(pair<int,int> i : g.at(d)) {
                p.emplace(l + i.second,i.first);
            }
        }
        swap(f,g);
    }
    cout<<mmin;
    return 0;
}