// Author : ysh
// 03/16/2022 Wed 21:02:32.74
// http://192.168.193.20/problem/9
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        bool o = 0;
        vector<int>f(a);
        vector<int>g(a+1);
        map<int,int>t,r;
        for(int j = 0;j<a;j++) {
            cin>>f[j];
            g[i+1] = g[i] + f[i];
        }
        //return 0;
        t.insert({0,1});
        for(int j = 0;j<a+1;j++) {
            int find = g[j] - b;
            auto found = t.lower_bound(find);
            if(found != t.end()) {
                r[g[j] - found->first]++;
            }
            t[g[j]]++;
        }
    }
    return 0;
}