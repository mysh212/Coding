// Author : ysh
// 10/01/2022 Sat 12:22:19.49
// https://tioj.ck.tp.edu.tw/problems/2266
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    int mmin = INT_MAX;
    int d = 0;
    int sig = 0;
    for(auto &i : f) {
        cin>>i.first;
        sig = sig + i.first;
    }
    int r = 0;
    for(auto &i : f) {
        cin>>i.second;
        if(i.second < mmin) {
            mmin = i.second;
            d = r;
        }
        r++;
    }
    f.erase(f.begin() + r);
    sig -= mmin;
    debug(sig);
    sort(f.begin(),f.end(),[] (pair<int,int>a,pair<int,int>b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    debug(f);
    deque<int>dd(n);
    priority_queue<int>q;
    for(int i = 1;i<=n;i++) {
        while((!f.empty()) && f.back().second <= i) {
            q.emplace(f.back().first);
            f.pop_back();
        }
        int now = n - i;
        if(q.empty()) {
            dd[now] = -1;
            continue;
        }
        int r = q.top();q.pop();
        dd.at(now) = r;
    }
    for(int i : dd) cerr<<i<<" ";
    while(!f.empty()) {
        q.push(f.back().first);
        f.pop_back();
    }
    while(!q.empty()) {
        cerr<<q.top()<<" ";
        q.pop();
    }
    cerr<<"\n";
    sig = 0;
    for(int i : dd) {
        if(i != -1) sig += i;
    }
    vector<int>ans({sig});
    for(int i = 0;i<n;i++) {
        if(dd.front() != -1) {
            int now = dd.front();dd.pop_front();
            q.emplace(now);
            sig -= now;
        }
        sig += q.top();
        q.pop();
        ans.push_back(sig);
    }
    while(!ans.empty()) {
        cout<<ans.back()<<" ";ans.pop_back();
    }
    return 2;
}