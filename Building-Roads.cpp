// Author : ysh
// 08/13/2022 Sat  7:44:15.40
// https://cses.fi/problemset/task/1666
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
inline int ff(int a) {
    if(f[a] == a) return a;
    return f[a] = ff(f[a]);
}
inline void mark(int a,int b) {
    f[ff(a)] = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    iota(f.begin(),f.end(),0);
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        mark(tmpa - 1,tmpb - 1);
    }
    queue<pair<int,int>>q;
    int last = ff(0);
    for(int i = 1;i<a;i++) {
        if(last != ff(i)) {
            q.emplace(i - 1,i);
            mark(i,i - 1);
        }
    }
    cout<<q.size()<<"\n";
    while(!q.empty()) {
        auto now = q.front();q.pop();
        cout<<now.first + 1<<" "<<now.second + 1<<"\n";
    }
    return 0;
}