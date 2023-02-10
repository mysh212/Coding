// Author : ysh
// 02/06/2023 Mon 22:14:08.60
#include<bits/stdc++.h>
using namespace std;
struct box{
    int now,d,n,r;
    box(int now = 0,int d = 0,int n = 0,int r = 0):
        now(now), d(d), n(n), r(r) {};
    inline bool operator<(const box a) const {
        if(now == a.now) return d < a.d;
        return now < a.now;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.first;
    for(auto &i : f) cin>>i.second;

    priority_queue<box>q;
    int t = 1;
    for(auto &i : f) q.push(box(i.first,i.second,t++,0));
    t = 0;
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int r = now.now;
        int d = now.d;
        int n = now.n;
        int time = now.r;
        if(time != t) {
            q.push(box(max(0,r - d * (t - time)),d,n,t));
        }
        if(time == t) {
            cout<<n<<" ";
        }
    }
    return 0;
}