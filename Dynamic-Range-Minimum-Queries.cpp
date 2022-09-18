// Author : ysh
// 09/18/2022 Sun  8:56:55.59
// https://cses.fi/problemset/task/1649
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
#define int long long
inline int cp(int a,int b) {
    return min(a,b);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree<int> t(f,cp);
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int a,b;cin>>a>>b;
            // t.check();
            t.add(a - 1,b - f.at(a - 1));
            f.at(a - 1) = b;
            // t.check();
        }
        if(tmp == 2) {
            int a,b;cin>>a>>b;
            cout<<t.sum(a - 1,b - 1)<<"\n";
        }
    }
    return 0;
}