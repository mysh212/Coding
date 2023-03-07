// Author : ysh
// 03/04/2023 Sat 11:56:36.69
// https://tioj.ck.tp.edu.tw/problems/2052
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

#define debug(i) i
#define eo(i) i
int r;
vector<vector<int>>mk;
int bigc(int a,int b) {
    if(b == 0 || b == a) return 1;
    eo(a);eo(b);eo(mk.at(a).at(b));
    return (mk.at(a).at(b) == -1 ? mk.at(a).at(b) = (bigc(a - 1,b - 1) + bigc(a - 1,b)) % r : mk.at(a).at(b));
}
int ck(vector<int>&m,int n) {
    int ans = 1;
    for(int &i : m) {
        ans = ans * bigc(n,i);
        n = n - i;
        ans = ans % r;
    }
    debug(m);
    return eo(ans);
}
int check(vector<int>&m,int n,int t) {
    int ans = 0;
    for(int i = 1;i<t;i++) {
        if(m[i] == 0) continue;
        m[i]--;
        ans = ans + ck(m,n);
        m[i]++;
    }
    return ans % r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>r;
    string a;cin>>a;
    int n;
    n = a.size();
    mk.resize(n,vector<int>(n,-1));
    vector<int>f(n),g(n);
    for(int i = 0;i<n;i++) {
        g.at(i) = f.at(i) = a.at(i);
    }
    int tt = 0;
    sort(g.begin(),g.end());
    g.resize(unique(g.begin(),g.end()) - g.begin());
    tt = g.size();
    vector<int>c(tt + 1);
    for(int &i : f) {
        i = ((int) (lower_bound(g.begin(),g.end(),i) - g.begin())) + 1;
        c[i]++;
    }
    
    long long ans = 0;
    for(int i = 0;i<n;i++) {
        ans = ans + check(c,n - 1 - i,f.at(i));
        --c[f.at(i)];
        ans = ans % r;
    }
    cout<<((ans) % r);
    return 0;
}