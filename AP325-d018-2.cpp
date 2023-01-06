// Author : ysh
// 01/06/2023 Fri 11:43:14.39
// https://judge.tcirc.tw/ShowProblem?problemid=d018
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// #define int int

int b;

int gcd(int x,int y,int &a,int &b) {
    if(y == 0) {
        a = 0;b = 1;
        return x;
    }
    int ans = gcd(y,x % y,a,b);
    int tmp = a;
    a = b - (x / y) * a;
    b = tmp;
    return ans;
}
int ck(int x) {
    int a,b;a = 0,b = 1;
    gcd(::b,x,a,b);
    return (a % ::b + ::b) % ::b;
}

void check(vector<int>&f,int l,int r,int now,map<int,int>&m) {
    if(l == r + 1) {
        m[now]++;
        return;
    }
    check(f,l + 1,r,now * 1LL * f.at(l) % b,m);
    check(f,l + 1,r,now,m);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    cin>>b;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int mid = n >> 1;
    long long ans = 0;
    map<int,int>l;
    map<int,int>r;
    check(f,0,mid,1,l);
    check(f,mid + 1,n - 1,1,r);
    l[1]--;
    r[1]--;
    debug(l);
    debug(r);
    for(auto i : l) {
        long long now = ck(i.first);
        if(r.find(now) == r.end()) {
            continue;
        }
        ans = ans + i.second * r.find(now)->second;
        ans = ans % b;
    }
    if(l.find(1) != l.end()) ans = ans + l.find(1)->second;
    if(r.find(1) != r.end()) ans = ans + r.find(1)->second;
    ans = ans % b;
    cout<<ans;
    return 0;
}