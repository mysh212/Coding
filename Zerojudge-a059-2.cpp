// Author : ysh
// 07/04/2022 Mon 16:56:48.46
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f;
    for(int i = 1;i<1000;i++) {
        f.push_back(i * i);
    }
    map<int,int>m;
    int last = 0;
    m.insert({-1,0});
    for(int i : f) {
        m.insert({i,last + i});
        last = last + i;
    }
    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        int sig = prev(m.upper_bound(b))->second - prev(m.lower_bound(a))->second;
        cout<<"Case "<<i + 1<<": "<<sig<<"\n";
    }
    return 0;
}