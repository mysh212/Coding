// Author : ysh
// 2023/10/05 Thu 11:23:14
// https://codeforces.com/contest/1548/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct table{
    vector<vector<int>>f;
    int n,m;
    
    table(vector<int>&v):
        n(v.size()), m(__lg(v.size()) + 1) {
            f.resize(n,vector<int>(m));
            for(int i = 0;i<n;i++) f.at(i).at(0) = v.at(i);
            for(int i = 1;i<=m;i++) {
                for(int j = 0;j + (1 << i) <= n;j++) {
                    f.at(j).at(i) = __gcd(f.at(j).at(i - 1),f.at(j + (1 << (i - 1))).at(i - 1));
                }
            }
        }
        
    int get(int l,int r) {
        // cerr<<l<<" "<<r<<"\n";
        // assert(r >= l && r  < n && l >= 0);
        if(l > r) swap(l,r);
        l = max(l,0LL);
        r = min(n - 1,r);
        int g = __lg(r - l + 1);
        return __gcd(f.at(l).at(g),f.at(r - (1 << g) + 1).at(g));
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // vector<int>f({2,4,8,4,3,5,3,2,4,5});
    // int n = f.size();
    // table t = table(f);
    // for(int i = 0;i<n;i++) {
    //     for(int j = i;j<n;j++) {
    //         int ans = f.at(i);
    //         for(int k = i;k<=j;k++) {
    //             ans = __gcd(ans,f.at(k));
    //         }
    //         cout<<(ans == t.get(i,j) ? "ok" : "ERROR")<<"\n";
    //     }
    // }
    
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        vector<int>g;
        for(int &i : f) {
            cin>>i;
        }
        if(n == 1) {
            cout<<1<<" ";
            continue;
        }
        for(int i = 1;i<n;i++) {
            g.push_back(abs(f.at(i) - f.at(i - 1)));
        }
        table t = table(g);
        int ans = (g.at(0) == 1 ? 0 : 1);
        int l,r;l = r = 0;
        while(r != n - 2) {
            r++;
            while(t.get(l,r) == 1 && l + 1 <= r) l++;
            if(t.get(l,r) != 1) ans = max(ans,(r - l + 1));
        } 
        cout<<ans + 1<<" ";
    }
    return 0;
}