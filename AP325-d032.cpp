// Author : ysh
// 07/17/2022 Sun  8:07:47.64
// https://judge.tcirc.tw/ShowProblem?problemid=d032
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>g;
    priority_queue<pair<int,int>>s;
    //g.push({0,-1});
    //s.push({0,-1});
    int mmax = 0;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        g.push({tmp,i});
        s.push({tmp,i});
        if(i == 0) continue;
        int l = i - b;
        auto now = g.top();
        while(!g.empty()) {
            if(now.second <= l) {
                g.pop();now = g.top();
                continue;
            }
            break;
        }
        auto nows = s.top();
        while(!s.empty()) {
            if(nows.second <= l) {
                s.pop();nows = s.top();
                continue;
            }
            break;
        }
        //printf("%d %d\n",now.first,nows.first);
        mmax = max(mmax,abs(now.first - nows.first));
    }
    cout<<mmax;
    return 0;
}