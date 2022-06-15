// Author : ysh
// 06/14/2022 Tue 23:15:14.92
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a);
        for(int i = 0;i<a;i++) {
            cin>>f[i];
            if(i != 0) f[i] = f[i - 1] + f[i];
        }
        map<int,int>m;
        m.insert(make_pair(0,-1));
        int mmax = -1;
        for(int i = 0;i<a;i++) {
            // for(auto i : m) cout<<i.first<<" ";
            // cout<<"\n";
            if(m.find(f[i] - b) != m.end()) mmax = max(mmax,i - m.find(f[i] - b)->second);
            if(m.find(f[i]) == m.end()) m.emplace(f[i],i);
            if(f[i] == 0 && m.find(0)->second == -1) m.emplace(0,i);
        }
        if(mmax == -1) cout<<-1<<"\n";
        else cout<<a - mmax<<"\n";
    }
    return 0;
}