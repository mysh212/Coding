// Author : ysh
// 01/30/2023 Mon 20:15:29.40
// https://tioj.ck.tp.edu.tw/problems/2195
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n),down(n);
    map<int,int>m;
    int t = 0;
    for(int &i : f) {
        cin>>i;
        m.insert({i,t++});
    }
    for(int i = 0;i<n;i++) {
        cin>>down.at(i);
        g.at(m.find(down.at(i))->second) = i;
    }
    // for(int &i : g) cerr<<i<<" ";
    // cerr<<"\n";
    vector<int>v;
    vector<int>mark(n + 1);
    vector<int>re,start;
    for(int i = 0;i<n;i++) {
        int now = g.at(i);
        auto found = upper_bound(v.begin(),v.end(),now);
        if(found == v.end()) {
            if(found != v.begin()) mark.at(now) = re.back();
            v.push_back(now);
            re.push_back(now);
            start = vector<int>({now});
        } else {
            if(down.at(now) > down.at(re.at(found - v.begin()))) {
                re.at(found - v.begin()) = now;
            }
            if(found != v.begin()) {
                mark.at(now) = re.at(found - v.begin() - 1);
            }
            if(found - v.begin() == v.size() - 1) start.push_back(now);
            *found = now;
        }
        for(int i : v) cerr<<down.at(i)<<" ";
        cerr<<"\n";
    }
    // for(int &i : mark) cerr<<i<<" ";
    // sort(start.begin(),start.end(),[&] (int a,int b) {
    //     return down.at(a) > down.at(b);
    // });
    vector<vector<int>>anss;
    for(int &now : start) {
        t = v.size();
        anss.push_back({});
        auto &ans = anss.at(anss.size() - 1);
        while(t--) {
            ans.push_back(down.at(now));
            now = mark.at(now);
        }
    }
    cerr<<anss.size();
    auto ans = *max_element(anss.begin(),anss.end(),[&] (vector<int>&a,vector<int>&b) {
        for(int i = v.size() - 1;i>=0;i--) {
            if(a.at(i) != b.at(i)) return a.at(i) < b.at(i);
        }
        return a < b;
    });
    reverse(ans.begin(),ans.end());
    for(int &i : ans) cout<<i<<" ";
    cout<<"\n";
    return 0;
}