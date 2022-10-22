// Author : ysh
// 10/03/2022 Mon  9:56:19.88
// https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<int,bool>m;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        m.insert({a,1});
        m.insert({b,0});
    }
    int now = 0;
    int mmax = 0;
    for(auto i : m) {
        if(i.second) now++;
        else now--;
        mmax = max(mmax,now);
    }
    cout<<mmax;
    return 0;
}