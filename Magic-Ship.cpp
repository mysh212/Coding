// Author : ysh
// 2023/09/19 Tue 18:14:19
// https://codeforces.com/problemset/problem/1117/C
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
#define int long long
map<char,int> d({{'U',3},{'D',1},{'R',0},{'L',2}});
const int xx[] = {-1,0,1,0};
const int yy[] = {0,1,0,-1};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x,y;cin>>x>>y;
    int nx,ny;cin>>nx>>ny;
    int t = x;
    int n;cin>>n;
    string a;cin>>a;
    vector<int>rx({0}),ry({0});
    int lx,ly;lx = ly = 0;
    for(char i : a) {
        rx.push_back(xx[d[i]]);
        ry.push_back(yy[d[i]]);
        rx.back() = lx += rx.back();
        ry.back() = ly += ry.back();
    }
    // debug(rx,ry);

    function<bool(int)> check = [&] (int x) {
        int lx = nx + rx.back() * (x / n) + rx.at(x % n);
        int ly = ny + ry.back() * (x / n) + ry.at(x % n);
        debug(x,nx,ny,lx,ly);
        return x >= abs(lx - t) + abs(ly - y);
    };

    function<int(int,int)> ck = [&] (int l,int r) {
        if(l == r) return l;
        int mid = (l + r) >> 1;
        if(check(mid)) return ck(l,mid);
        return ck(mid + 1,r);
    };

    int ans = ck(0,1e15);
    cout<<(ans == 1e15 ? -1 : ans);
    return 0;
}