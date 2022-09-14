// Author : ysh
// 09/14/2022 Wed 12:18:33.62
// https://atcoder.jp/contests/dp/tasks/dp_n
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    vector<vector<int>>mark(n,vector<int>(n));
    function<int(int,int)> check = [&] (int l,int r) {
        if(l + 1 == r) return f.at(l) + f.at(r);
        int mmin = LONG_LONG_MAX;
        for(int i = l + 1;i<r;i++) {
            mmin = min(check(l,i) + check(i + 1,r),mmin);
        }
        return mmin + (f.at(l) + f.at(r));
    };
    cout<<check(0,n - 1);
    return 0;
}