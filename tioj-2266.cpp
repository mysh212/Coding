// Author : ysh
// 10/01/2022 Sat 12:22:19.49
// https://tioj.ck.tp.edu.tw/problems/2266
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    int mmin = LONG_LONG_MAX;
    int d = 0;
    for(auto &i : f) {
        cin>>i.first;
        // sig = sig + i.first;
    }
    int r = 0;
    for(auto &i : f) {
        cin>>i.second;
        assert(i.second != 0);
        if(i.first < mmin) {
            mmin = i.first;
            d = r;
        }
        if(i.first == mmin && i.second > f.at(d).second) {
            mmin = i.first;
            d = r;
        }
        r++;
    }
    f.erase(f.begin() + d);
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    vector<int>dd;
    priority_queue<int>q;
    for(int i = 1;i<n;i++) {
        while((!f.empty()) && f.back().second <= i) {
            q.emplace(f.back().first);
            f.pop_back();
        }
        int now = n - i - 1;
        if(q.empty()) {
            dd.push_back(-1);
            continue;
        }
        int r = q.top();q.pop();
        dd.push_back(r);
    }
    // for(int i : dd) cerr<<i<<" ";
    while(!f.empty()) {
        q.push(f.back().first);
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
    }
    vector<int>ans({sig});
    for(int i = 0;i<n - 1;i++) {
        if(dd.back() != -1) {
            int now = dd.back();dd.pop_back();
            q.emplace(now);
            sig -= now;
        } else {
            dd.pop_back();
        }
        sig += q.top();
        q.pop();
        ans.push_back(sig);
    }
    while(!ans.empty()) {
        cout<<ans.back()<<" ";ans.pop_back();
    }
    return 0;
}