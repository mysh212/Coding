// Author : ysh
// 01/24/2023 Tue 10:12:14.27
// https://tioj.ck.tp.edu.tw/problems/2194
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>f,t,d;
vector<vector<int>>mark;
int check(int x,int m) {
    if(x == -1) return 0;
    if(x == 0) {
        int ans = 0;
        while(m--) {
            ans = ans + f.at(x);
            f.at(x) = f.at(x) - d.at(x);
        }
        return ans;
    }
    if(mark.at(x).at(m) != -1) return mark.at(x).at(m);
    debug(x,m);
    int r = m;
    int mmax = 0;
    int now = 0;
    while(m != 0) {
        if(m >= t.at(x - 1)) mmax = max(mmax,check(x - 1,m - t.at(x - 1)) + now);
        m--;
        now = now + f.at(x);
        f.at(x) = f.at(x) - d.at(x);
    }
    return mark.at(x).at(r) = mmax;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    f.resize(n);t.resize(n - 1);d.resize(n);
    mark.resize(n,vector<int>(m + 1,-1));
    for(int &i : t) {
        cin>>i;
    }
    for(int &i : f) {
        cin>>i;
    }
    for(int &i : d) {
        cin>>i;
    }
    cout<<check(n - 1,m);
    for(auto &i : mark) {for(int &j : i) cerr<<j<<" "; cerr<<"\n";}
    return 0;
}