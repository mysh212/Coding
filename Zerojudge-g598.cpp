// Author : ysh
// 09/06/2022 Tue 21:20:17.98
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
queue<pair<int,bool>>q,qf;
vector<bool>f,mark;
inline void mg(int a,int b) {
    if(!mark[a]) {
        qf.push({a,f[a]});
        f[a] = !f[b];
        q.push({a,mark[a]});
        mark[a] = 1;
        q.push({b,mark[b]});
        mark[b] = 1;
        return;
    }
    qf.push({b,f[b]});
    f[b] = !f[a];
    q.push({b,mark[b]});
    mark[b] = 1;
    return;
}
inline bool check(int a,int b) {
    if((!mark[a]) || (!mark[b])) {
        mg(a,b);
        return 1;
    }
    return (f[a] == !f[b]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    mark.resize(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        mg(a,b);
    }
    vector<bool>bp,mp;
    int c,d;cin>>c>>d;
    for(int i = 1;i<=c;i++) {
        while(!q.empty()) {
            if(i == 1) {
                q.pop();
                continue;
            }
            mark[q.front().first] = q.front().second;q.pop();
        }
        while(!qf.empty()) {
            if(i == 1) {
                qf.pop();
                continue;
            }
            f[qf.front().first] = qf.front().second;qf.pop();
        }
        for(bool i : f) cout<<(int) i;
        cout<<"\n";
        for(bool i : mark) cout<<(int) i;
        cout<<"\n";
        for(int j = 0;j<d;j++) {
            int a,b;cin>>a>>b;
            if(!check(a,b)) {
                cout<<i<<"\n";
                break;
            }
        for(bool i : f) cout<<(int) i;
        cout<<"\n";
        for(bool i : mark) cout<<(int) i;
        cout<<"\n";
        }
    }
    return 0;
}