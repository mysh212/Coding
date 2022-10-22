// Author : ysh
// 10/20/2022 Thu  9:03:51.51
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
// #define int long long
int check(int x) {
    if(x == 1) return f.at(1) = 1;
    if(x == 2) return f.at(2) = 1;
    if(f.at(x) != 0) return f.at(x);
    return f.at(x) = check(x - 1) + check(x - 2);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f.resize(37);check(36);
    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        auto found = lower_bound(f.begin(),f.end(),tmp);
        if(*found == tmp) cout<<found - f.begin()<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}