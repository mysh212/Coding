// Author : ysh
// 2024/01/05 Fri 13:30:24
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),g(b);
    for(int &i : f) cin>>i;
    for(int &j : g) cin>>j;

    if(a < b) swap(a,b),swap(f,g);
    int ans = INT_MIN;

    vector<vector<int>>mark(a,vector<int>(b));
    for(int k = 0;k<=1;k++) {
        for(int i = 0;i<a;i++) {
            int last = 0;
            for(int j = 0;j < b;j++) {
                if(i + j == a) last = 0;
                last = max(f.at((i + j) % a) * g.at(j),last + f.at((i + j) % a) * g.at(j));
                ans = max(ans,last);
            }
        }
        reverse(g.begin(),g.end());
    }

    cout<<ans;
    return 0;
}