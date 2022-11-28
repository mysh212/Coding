// Author : ysh
// 11/27/2022 Sun 13:04:10.95
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
int check(int a,int b) {
    if(last == 0) last = (a * (a - 1)) >> 1;
    else last = last * (a + 1 - b) / b;
    last = last % r;
    return last;
}
int fast(int x,int r) {
    if(r == 1) return x;
    int tmp = fast(x,r >> 1);
    if(r & 1) return (((tmp * tmp) % ::r) * x) % ::r;
    return (tmp * tmp) % ::r;
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
    int rr = (n >> 1);
    int sig = 0;
    for(int i = 2;i<=(n - rr);i++) {
        sig = (sig + check(n - rr,i) * floor(n - rr - i) * floor(rr)) % r;
        // cout<<floor(n - i)<<" ";
        // cerr<<sig<<"\n";
    }
    sig = sig * n;
    int tmp = sig;cerr<<sig<<" ";
    if(!(n & 1)) {
        cout<<(tmp + n * floor(n - 2)) % r;
        return 0;
    }
    cout<<tmp;
    return 0;
}