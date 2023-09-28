// Author : ysh
// 2023/06/27 Tue 09:39:13
// https://neoj.sprout.tw/problem/367/
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree> // exact
#include<max_value>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<max_value>f(a);
    for(auto &i : f) {
        cin>>i;
    }
    seg_tree<max_value>t(f);

    while(b--) {
        int a;cin>>a;
        if(a == 1) {
            int l,r,v;cin>>l>>r>>v;
            t.add(l - 1,r - 1,v);
        }
        if(a == 2) {
            int l,r;cin>>l>>r;
            cout<<t.sum(l - 1,r - 1)<<"\n";
        }
        // t.debug();
    }
    return 0;
}