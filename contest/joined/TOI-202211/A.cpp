// Author : ysh
// 11/30/2022 Wed 21:10:47.58
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

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a),re(a);
    vector<int>to(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        f.at(a).push_back(b);
        re.at(b).push_back(a);
        to.at(a)++;
    }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(to.at(i) == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front();q.pop();
        for(int &i : re.at(now)) if(--to.at(i) == 0) {
            q.push(i);
        }
    }
    debug(to);
    vector<bool>mark(a);
    function<void(int)> check = [&] (int x) {
        if(mark.at(x)) return;
        mark.at(x) = 1;
        for(int &i : re.at(x)) {
            check(i);
        }
        return;
    };
    bool c = 0;
    for(int i = 0;i<a;i++) {
        if(to.at(i) != 0) {
            //check(i);
            cout<<i<<" ";
            c = 1;
        }
    }
    if(!c) cout<<-1;
    return 0;
    for(int i = 0;i<a;i++) {
        if(mark.at(i)) cout<<i<<" ";
    }
    return 0;
}