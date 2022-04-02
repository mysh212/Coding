// Author : ysh
// 03/16/2022 Wed 21:02:32.74
// http://192.168.193.20/problem/9
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int a,b;cin>>a>>b;
        bool o = 0;
        vector<int>f(a);
        vector<int>g(a+1);
        map<int,int>t,r;
        for(int j = 0;j<a;j++) {
            cin>>f[j];
            g[j+1] = g[j] + f[j];
        }
        //for(int i : g) cout<<i<<" ";
        //cout<<"\n";
        //return 0;
        t.insert({0,1});
        int mmax,ans;mmax=INT_MIN;ans=0;
        for(int j = 1;j<a+1;j++) {
            int find = g[j] - b;
            auto found = t.lower_bound(find);
            if(found == t.end()) {
                t[g[j]]++;
                continue;
            }
            if(g[j] - found->first > mmax) {
                mmax = g[j] - found->first;
                ans = found->second;
                // cout<<"=";
                t[g[j]]++;
                continue;
            }
            if(g[j] - found->first == mmax) {
                ans += found->second;
                // cout<<"+";
            }
            t[g[j]]++;
            // for(auto i : t) cout<<i.first<<" ";
            // cout<<"\n";
            // for(auto i : t) cout<<i.second<<" ";
            // cout<<"\n";
            // printf("t[%d]++",g[j]);
        }
        if(mmax != 0&&mmax != INT_MIN) cout<<mmax<<" "<<ans<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}