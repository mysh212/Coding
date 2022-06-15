// Author : ysh
// 06/13/2022 Mon 11:22:31.15
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define int long long
vector<vector<int>>f(MAX,vector<int>(MAX));
vector<int>r,g;
int n,m;
int check();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    r.resize(n);
    g.resize(m);
    for(int &i : r) {
        cin>>i;
    }
    for(int &i : g) {
        cin>>i;
    }
    int mmax = check();
    reverse(g.begin(),g.end());
    mmax = max(mmax,check());
    cout<<mmax;
    return 0;
}
int check() {
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            f[i][j] = r.at(i) * g.at(j);
        }
    }
    // for(auto i : f) {
    //     for(int j : i) {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    int mmax = INT_MIN;
    int sig = 0;
    for(int i = 0;i<n;i++) {
        sig = 0;
        int pi = i;
        for(int j = 0;j<m;j++) {
            sig += f[pi][j];
            mmax = max(mmax,sig);
            if(sig < 0) sig = 0;
            pi++;
            if(pi >= n) {
                sig = 0;
                pi -= n;
            }
        }
    }
    return mmax;
}