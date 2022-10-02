// Author : ysh
// 10/01/2022 Sat 12:22:19.49
// https://tioj.ck.tp.edu.tw/problems/2266
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define printf(...) '*'
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    int d = 0;
    for(auto &i : f) {
        cin>>i.first;
    }
    for(auto &i : f) {
        cin>>i.second;
        assert(i.second != 0);
        // if(i.first < mmin) {
        //     mmin = i.first;
        //     d = r;
        // }
        // if(i.first == mmin && i.second > f.at(d).second) {
        //     mmin = i.first;
        //     d = r;
        // }
        // r++;
    }
    // int tag = f.at(d).second;
    // f.erase(f.begin() + d);
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    vector<int>dd;
    // priority_queue<pair<int,int>>q;
    multiset<pair<int,int>>s;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(int i = 1;i<n;i++) {    
        while((!f.empty()) && f.back().second <= i) {
            s.insert(f.back());
            f.pop_back();
        }
        // int now = n - i - 1;
        if(s.empty()) {
            dd.push_back(-1);
            continue;
        }
        // if(*prev(s.end()) == make_pair(mmin,tag)) {
        //     s.erase(prev(s.end()));
        //     dd.push_back(-2);
        //     continue;
        // }
        int r = prev(s.end())->first;s.erase(prev(s.end()));
        dd.push_back(r);
    }
    bool o = 0;
    while(!f.empty()) {
        s.insert(f.back());
        f.pop_back();
    }
    // while(!q.empty()) {
    //     cerr<<q.top()<<" ";
    //     q.pop();
    // }
    // cerr<<"\n";
    int sig = 0;
    sig = 0;
    for(int i : dd) {
        if(i != -1) sig += i;
        // if(i == -2) sig += mmin + 2;
    }
    int nn = (s.begin())->first;
    s.erase(s.begin());
    vector<int>ans({sig});
    for(int i = 0;i<n - 1;i++) {
        // if(dd.back() == -2) {
        //     if(o) {
        //         dd.back() = mmin;
        //     } else {
        //         sig = sig + nn;
        //         sig = sig - mmin;
        //         o = 1;
        //         ans.push_back(sig);
        //         dd.pop_back();
        //         continue;
        //     }
        // }
        // assert(!s.empty());
        if(dd.back() != -1) {
            int now = dd.back();dd.pop_back();
            if(now < nn) {
                // s.emplace(nn,0);
                sig = sig + nn - now;
                swap(nn,now);
            }
            s.emplace(now,0);
            sig -= now;
        } else {
            dd.pop_back();
        }
        sig += prev(s.end())->first;
        s.erase(prev(s.end()));
        ans.push_back(sig);
    }
    while(!ans.empty()) {
        cout<<ans.back()<<" ";ans.pop_back();
    }
    return 0;
}