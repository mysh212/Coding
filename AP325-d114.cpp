// Author : ysh
// 03/06/2023 Mon 13:00:21.81
// https://judge.tcirc.tw/ShowProblem?problemid=d114
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
int check(vector<int>&v,vector<vector<int>>&f,int last,int x) {
    // int d,secd;d = secd = INT_MIN;
    int sig = 0;
    for(int &i : f.at(x)) {
        if(i == last) continue;
        int tmp = check(v,f,x,i);
        sig = sig + tmp;
    }
    assert(sig >= 0);
    ans = max(ans,sig + v.at(x));
    return max(0LL,sig + v.at(x));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>v(n);
    for(int &i : v) {
        cin>>i;
    }
    vector<vector<int>>f(n);
    for(int i = 1;i<n;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    check(v,f,-1,0);
    cout<<ans;
    return 0;
}