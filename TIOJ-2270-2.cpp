// Author : ysh
// 10/07/2022 Fri 13:27:30.72
// https://tioj.ck.tp.edu.tw/problems/2270
#include<bits/stdc++.h>
using namespace std;
vector<int>mark({1,1,2});
int floor(int x) {
    // cerr<<'['<<x<<']';
    if(mark.size() >= x + 1) return mark.at(x);
    int tmp = floor(x - 1);
    mark.push_back(tmp);
    return tmp;
}
int main() {
    int a,b;cin>>a>>b;
    int c[a] = {};
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;char cc;
        cin>>a>>cc>>b;
        a--;b--;
        if(cc == '>') {
            f.at(b).push_back(a);
            c[a]++;
            continue;
        }
        f.at(a).push_back(b);
        c[b]++;
    }
    function<int(int x)> check = [&] (int x) {
        
    }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(c[i] == 0) q.emplace(i);
    }
    vector<bool>mark(a);
    queue<int>ans;
    int t = 1;
    while(!q.empty()) {
        int now = q.front();q.pop();
        if(mark.at(now)) continue;
        mark.at(now) = 1;
        ans.push(now + 1);
        int r = 0;
        for(int &i : f.at(now)) {
            r++;
            c[i]--;
            if(c[i] == 0) q.emplace(i);
        }
        t = t * floor(r);
    }
    for(int i = 0;i<a;i++) {
        if(c[i] != 0) {
            // cout<<"NO";
            // return 0;
        }
    }
    cout<<"YES\n";
    while(!ans.empty()) {
        cout<<ans.front()<<"\n";ans.pop();
    }
    cout<<t;
    return 0;
}
