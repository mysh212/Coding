// Author : ysh
// 2025/03/29 Sat 19:29:12
// https://cses.fi/problemset/task/1091
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<int>f(a), g(b);
    cin>>f>>g;

    // sort(all(f));
    multiset<int, greater<int>> s(all(f));
    
    repo(&i, g) {
        auto found = s.lower_bound(i);
        if(found == s.end()) outl(-1);
        else {
            outl(*found);
            s.erase(found);
        }
    }
    return 0;
}