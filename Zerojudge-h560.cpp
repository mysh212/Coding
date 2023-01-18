// Author : ysh
// 01/17/2023 Tue 20:50:11.40
#include<bits/stdc++.h>
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

using namespace std;
bool check(int n,vector<bool>&f) {
    int a,b;a = b = 0;
    for(int i = 0;i<n;i = i + 2) {
        a = a + (int) f.at(i);
    }
    for(int i = 1;i<n;i = i + 2) {
        b = b + (int) f.at(i);
    }
    debug(a,b);
    return (abs(a - b) % 11 == 0);
}
bool nt(int n,vector<bool>&f) {
    bool c = 0;
    while(next_permutation(f.begin(),f.end())) {
        if(check(n,f)) {
            c = 1;
            break;
        }
    }
    return c;
}
bool pv(int n,vector<bool>&f) {
    bool c = 0;
    while(prev_permutation(f.begin(),f.end())) {
        if(check(n,f)) {
            c = 1;
            break;
        }
    }
    return c;
}
#define endno {cout<<"-1\n";return 0;}
#define show(j) {for(int i : j) cout<<(i ? 2 : 0); cout<<"\n";}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n = a + b;
    vector<bool>f(n);
    for(int i = n - 1,len = max(n - b,0);i >= len;i--) {
        f.at(i) = 1;
    }
    bool r = 0;
    if(!(b & 1) || check(n,f)) r = 1;
    if(!r) if(!nt(n,f)) endno;
    if(!nt(n,f)) endno;
    vector<bool>v(f);
    // show(v);
    for(int i = 0;i<n;i++) {
        if(i < b) f.at(i) = 1;
        else f.at(i) = 0;
    }
    // show(f);
    if(!r) if(!pv(n,f)) endno;
    if(!pv(n,f)) endno;
    if(v == f) endno;
    show(f);
    show(v);
    return 0;
}