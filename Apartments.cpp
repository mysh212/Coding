// Author : ysh
// 2025/03/29 Sat 18:59:39
// https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vc<int>f(a);
    vc<int>g(b);
    cin>>f>>g;
    
    sort(all(f));
    sort(all(g));
    // repo(&i, g) i = i - c;

    int ans = 0;
    int l, r;l = r = 0;
    while(l != a && r != b) {
        if(g.at(r) < f.at(l) - c) r++;
        else if(g.at(r) > f.at(l) + c) l++;
        else ans++, l++, r++;
    }

    out(ans);
    return 0;
}