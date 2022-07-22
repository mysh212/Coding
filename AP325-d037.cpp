// Author : ysh
// 07/20/2022 Wed 19:09:21.44
// https://judge.tcirc.tw/ShowProblem?problemid=d037
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define x first
#define y second
bool n = 0;
struct cp{
    bool operator() (pair<int,int> a,pair<int,int>b) {
        if(n) return a.second < b.second;
        return a.second > b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<pair<int,int>>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i].first;
    }
    for(int i = 0;i<a;i++) {
        cin>>f[i].second;
    }
    sort(f.begin(),f.end());
    int mmax = 0;
    for(int i = 1;i<=2;i++) {
        n = i & 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cp>q;
        q.push(f[0]);
        for(int i = 1;i<a;i++) {
            q.push(f[i]);
            auto now = q.top();
            int l = f[i].x - b;
            bool c = 0;
            while(now.x < l) {
                if(q.empty()) {
                    c = 1;
                    break;
                }
                q.pop();now = q.top();
            }
            if(c) continue;
            
            if(mmax < abs(f[i].y - now.y)) {
                mmax = abs(f[i].y - now.y);
                debug(f[i].x,f[i].y,now.x,now.y);
            }
        }
    }
    cout<<mmax;
    return 0;
}