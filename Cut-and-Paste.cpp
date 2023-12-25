// Author : ysh
// 2023/12/18 Mon 14:31:07
// https://cses.fi/problemset/task/2072
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    rope<char>r(a);
    string t;cin>>t;
    for(char i : t) r += i;

    while(b--) {
        int a,b;cin>>a>>b;
        r.append(r.substr(a - 1,(b - a + 1)));
        r.erase(a - 1,b - a + 1);
    }

    for(char i : r) cout<<i;
    return 0;
}