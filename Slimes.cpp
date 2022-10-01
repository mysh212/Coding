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
    deque<int>f(n);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }
    f.push_front(0);
    vector<vector<int>>mark(n + 1,vector<int>(n + 1));
    function<int(int,int)> check = [&] (int l,int r) {
        if(l + 1 == r) return 0LL;
        if(mark[l][r] != 0) return mark[l][r];
        int mmin = LONG_LONG_MAX;
        for(int i = l + 1;i + 1<r;i++) {
            mmin = min(check(l,i) + check(i + 1,r),mmin);
        }
        return mark[l][r] = mmin + (f.at(r) - f.at(l));
    };
    cout<<check(0,n);
    return 0;
}