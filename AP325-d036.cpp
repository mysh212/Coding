// Author : ysh
// 07/18/2022 Mon 15:39:31.32
// https://judge.tcirc.tw/ShowProblem?problemid=d036
#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
vector<int>f;
int mmax,all;
int check(int,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(b);
    for(int i = 0;i<b;i++) {
        cin>>f[i];
        if(m.find(f[i]) == m.end()) all++;
        m.insert({f[i],0});
    }
}
int check(int l,int r) {
    int mid = (l + r) >> 1;
    int sig = (check(l,mid) + check(mid + 1,r));
    map<int,int>n;
    queue<int>q;
    int nl = l,nr = mid + 1;
    int now = 0;int up = 0;
    for(int i = l;i<=mid + 1;i++) {
        q.push(f[i]);
        n[f[i]]++;
        if(n[f[i]] == 2) {
            up++;
            now--;
        }
        if(n[f[i]] == 1) {
            now++;
        }
    }
    while(nr != r) {
        q.push(f[++nr])
        if(now == all) {
            sig++;
            auto t = q.front();q.pop();
            if(n[t] == 0) {
                now--;
            }
        }
    }
}