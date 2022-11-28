// Author : ysh
// 11/28/2022 Mon 21:12:09.56
// https://codeforces.com/contest/1764/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
int r;
vector<int>fl({1,2});
int floor(int x) {
    if(x == 0) return 1;
    if(fl.size() >= x) return fl.at(x - 1);
    fl.push_back((floor(x - 1) * x) % r);
    return fl.back();
}
int last = 0;
vector<vector<int>>mk;
int check(int a,int b) {
    if(b == 0) return 1;
    if(a == b) return 1;
    if(mk.at(a).at(b) != 0) return mk.at(a).at(b);
    else return mk.at(a).at(b) = (check(a - 1,b - 1) + check(a - 1,b)) % r;
    /*
    if(last == 0) last = (a * (a - 1)) >> 1;
    else last = last * (a + 1 - b) / b;
    last = last % r;
    //printf("C(%lld,%lld) = %lld\n",a,b,last);
    return last;
    */
}
int fast(int x,int r) {
    if(r == 1) return x;
    int tmp = fast(x,r >> 1);
    if(r & 1) return (((tmp * tmp) % ::r) * x) % ::r;
    return (tmp * tmp) % ::r;
}
int e(int x) {
    //cerr<<x<<"\n";
    return x;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    // for(int i = 0;i<5;i++) {
    //     cerr<<check(6,i + 2)<<"\n";
    // }
    // return 0;
    cin>>n;
    cin>>r;
    mk.resize(n,vector<int>(n));
    int rr = (n >> 1);
    int sig = 0;
    for(int i = rr;i<n - 1;i++) {
        for(int j = 2;j<=n - i;j++) {
            sig = (sig + (((rr << 1) - i) * e(check(n - i - 2,(j - 2))) % r) * e(floor(i + j - 2 - 1))) % r;
        }
    }
    /*
    for(int i = 2;i<=(n - rr);i++) {
        sig = (sig + ((check(n - rr,i) * floor(n - rr - i)) % r) * floor(rr)) % r;
        // cout<<floor(n - i)<<" ";
        // cerr<<sig<<"\n";
    }
    */
    sig = sig * n;
    int tmp = sig;
    if(!(n & 1)) {
        cout<<(tmp + n * floor(n - 2)) % r;
        return 0;
    }
    cout<<tmp % r;
    return 0;
}
