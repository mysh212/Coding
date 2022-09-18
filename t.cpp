// Author : ysh
// 09/18/2022 Sun  8:49:27.53
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree<int> t(f);
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        if(tmp == 2) {
            int r;cin>>r;
            cout<<t.rsum(r - 1,r - 1)<<"\n";
        }
        if(tmp == 1) {
            int a,b,c;cin>>a>>b>>c;
            t.radd(a - 1,b - 1,c);
        }
    }
    return 0;
}