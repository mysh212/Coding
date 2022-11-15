// Author : ysh
// 11/07/2022 Mon 10:21:30.08
// https://cses.fi/problemset/task/2189
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
pair<int,int> operator-(pair<int,int>a,pair<int,int>b) {
    return make_pair(a.x - b.x,a.y - b.y);
}
pair<int,int> operator*(pair<int,int>a,pair<int,int>b) {
    return make_pair(a.x * b.y,a.y * b.x);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        pair<int,int>a,b,c;cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        if((a.x - c.x) * (b.y - c.y) == (b.x - c.x) * (a.y - c.y)) {
            cout<<"TOUCH\n";
            continue;
        }
        pair<int,int> aa,bb;
        aa = a - c;
        bb = b - c;
        if(aa.x * bb.y - aa.y * bb.x > 0) cout<<"LEFT\n";
        if(aa.x * bb.y - aa.y * bb.x < 0) cout<<"RIGHT\n";
    }
    return 0;
}