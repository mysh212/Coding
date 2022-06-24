// Author : ysh
// 06/23/2022 Thu 17:16:01.49
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include<iostream>
#include<vector>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
vector<int>f,g;
vector<bool>c;
int a,b;
inline int check(int n) {
    if(c[n] == true && n <= a) {
        return g[n] = check(g[n]);
    }
    return n;
}
inline int findleft(int n) {
    if(c[n] == true && n >= 0) return f[n] = findleft(f[n]);
    if(n < 0) {
        return -1;
    }
    return n;
}
inline int findright(int n) {
    if(c[n] == true && n <= a) return g[n] = findright(g[n]);
    if(n > a) {
        return -1;
    }
    return n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a + 1);
    g.resize(a + 1);
    c.resize(a + 1);
    iota(f.begin(),f.end(),-1);
    iota(g.begin(),g.end(),1);
    for(int i = 0;i<b;i++) {
        debug(f,g);
        char s;cin>>s;
        if(s == '?') {
            int n;cin>>n;n = n - 1;
            n = check(n);
            if(n >= 0) cout<<(n == a ? -1 : n + 1)<<"\n";
            else cout<<"-1\n";
        }
        if(s == '-') {
            int n;cin>>n;
            c[n - 1] = 1;
            g[findleft(n - 1)] = findright(n - 1);
            f[findright(n - 1)] = findleft(n - 1);
        }
    }
    return 0;
}