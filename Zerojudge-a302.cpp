// Author : ysh
// 2024/01/10 Wed 11:29:22
#include<bits/stdc++.h>
using namespace std;
const int R = 10007;
vector<int>mkf({1});
#define int long long
int fl(int x) {
    if(x == 0) return 1;
    if(mkf.size() > x) return mkf.at(x);
    mkf.push_back((x * (fl(x - 1))) % R);
    return mkf.at(x);
}
int ck(int a,int b) {
    if(b == 0) return 1;
    int tmp = ck(a,b >> 1);
    if(b & 1) return (((tmp * tmp) % R) * a) % R;
    return (tmp * tmp) % R;
}
int rv(int x) {
    return ck(x,R - 2);
}
int check(int a,int b) {
    return (((fl(a) * rv(fl(b))) % R) * rv(fl(a - b))) % R;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
    cout<<(((check(c,d) * ck(a,d)) % R) * ck(b,e)) % R;
    return 0;
}