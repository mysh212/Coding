// Author : ysh
// 2026/10/29 Thu 18:47:28
#include<bits/stdc++.h>
using namespace std;
#include<slow>
vc<int>color;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;cin>>n>>m>>k>>q;
    vc<map<int, int>>f(n);
    re(m) {
        int a, b, c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).insert({b, c});
        f.at(b).insert({a, c});
    }

    re(q) {
        short op;cin>>op;
        if(op == 1) {
            
            continue;
        }
        if(op == 2) {

            continue;
        }
    }
}