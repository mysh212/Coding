// Author : ysh
// 02/13/2022 Sun 14:32:48.09
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool brk = 0;
inline void opt(bool n) {
    if(n) cout<<"yeah!";
    else cout<<"oh no...";
}
void check(int n,int sig,int c,int now) {
    if(brk) return;
    if(now == 6) {
        if(sig == c) {
            opt(1);
            brk = 1;
            return;
        } else {
            return;
        }
    }
    if(sig > c) return;
    check(n+1,sig + n,c,now+1);
    check(n+1,sig,c,now);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    b = b - (a - 1);
    c = c - ((a - 1) * 6);
    a = 1;
    if(c < 21) {
        opt(0);
        return 0;
    }
    if((b + 1) * 6 - 21 < c) {
        opt(0);
        return 0;
    }
    check(c/12,0,c,0);
    return 0;
}