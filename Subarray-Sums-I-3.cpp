// Author : ysh
// 03/02/2023 Thu 17:19:10.84
// https://cses.fi/problemset/task/1660/
// NF
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    long long sig = 0;
    vector<int>f(a);
    for(int &i : f) cin>>i;

    int ans = 0;
    int l = 0,r = 0;sig = f.at(0);
    while(r != a - 1) {
        if(sig < b) {
            r = r + 1;
            sig = sig + f.at(r);
        }
        if(sig > b) {
            l = l + 1;
            sig = sig - f.at(l - 1);
        }
        if(sig == b) {
            ans = ans + 1;
            r = r + 1;
            sig = sig + f.at(r);
        }
    }
    cout<<ans;
    return 0;
}