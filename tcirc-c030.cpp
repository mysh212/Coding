// Author : ysh
// 03/04/2023 Sat 22:45:33.46
// https://judge.tcirc.tw/ShowProblem?problemid=c030
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e9 + 7;
#define int long long
int fast(int x,int y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    int tmp = fast(x,y >> 1);
    if(y & 1) return (((tmp * tmp) % (R - 1)) * x) % (R - 1);
    return (tmp * tmp) % (R - 1);
}
int ffast(int x,int y) {
    if(y == 0) return 1;
    int tmp = ffast(x,y >> 1);
    if(y & 1) return (((tmp * tmp) % R) * x) % R;
    return (tmp * tmp) % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int x,y,z;cin>>x>>y>>z;
        int r = fast(y,z);
        cout<<ffast(x,r)<<"\n";
    }
    return 0;
}