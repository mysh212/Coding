// Author : ysh
// 07/04/2022 Mon 16:44:36.82
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f;
    for(int i = 1;i<1000;i++) {
        f.push_back(i * i);
    }
    int m;cin>>m;
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        int sig = 0;
        auto found = lower_bound(f.begin(),f.end(),a);
        for(auto j = found;j != f.end();j++) {
            if(*j > b) break;
            sig = sig + *j;
        }
        cout<<"Case "<<i + 1<<": "<<sig<<"\n";
    }
    return 0;
}