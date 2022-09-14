// Author : ysh
// 09/14/2022 Wed  8:27:04.80
// https://atcoder.jp/contests/dp/tasks/dp_q
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
#include<seg_tree>
int check(int a,int b) {
    return max(a,b);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    int mmax = 0;
    for(int &i : f) {
        cin>>i;
        mmax = max(mmax,i);
    }
    for(int &i : g) {
        cin>>i;
    }
    // vector<int>mark(mmax + 1);
    seg_tree<int>t((mmax + 1),check);
    int a,b;
    for(int i = 0;i<n;i++) {
        int tmp = t.sum(f.at(i),f.at(i));
        int mmax = t.sum(0,f.at(i) - 1);
        // t.check();
        // cerr<<1;
        if(mmax + g.at(i) > tmp) {
            t.add(f.at(i),mmax - tmp + g.at(i));
        }
        // cerr<<1;
        // for(int j = f.at(i) + 1;j<=mmax;j++) {
        //     // mark.at(j) = max(mark.at(j - 1),mark.at(j));
        //     if(mark.at(j - 1) > mark.at(j)) {
        //         mark.at(j) = mark.at(j - 1);
        //         continue;
        //     }
        //     break;
        // }
    // debug(mark);
    }
    cout<<t.sum(0,mmax);
    return 0;
}