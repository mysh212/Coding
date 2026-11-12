// Author : ysh
// 2026/11/05 Thu 17:50:23
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;
    vc<vc<bool>>f(n, vc<bool>(m));
    re(i, n) re(j, m) {
        char tmp;cin>>tmp;
        f.at(i).at(j) = (tmp == 'Y');
    }

    
}