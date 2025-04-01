// Author : ysh
// 2025/03/30 Sun 23:48:02
// https://cses.fi/problemset/task/1640
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    map<int,int>m;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        auto found = m.find(b - tmp);
        if(found != m.end()) {
            cout<<found->second + 1<<" "<<i + 1;
            return 0;
        }
        m.insert({tmp, i});
    }

    cout<<"IMPOSSIBLE";
    return 0;
}