// Author : ysh
// 05/22/2022 Sun 10:58:32.16
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    {
    int a,b;
    for(int i = 0;i<n;i++) {
        cin>>a>>b;
        f[i] = {a,b};
    }
    }
    sort(f.begin(),f.end());
    vector<int>v;
    //int nowx = -1;
    for(int i = 0;i<n;i++) {
        //if(nowx == f[i].first) continue;
        auto now = f[i].second;
        auto found = upper_bound(v.begin(),v.end(),now);
        if(found != v.end()) v[found - v.begin()] = now;
        else v.push_back(now);
        //nowx = f[i].first;
    }
    cout<<v.size()<<"\n";
    return 0;
}