// Author : ysh
// 04/03/2022 Sun 11:02:42.35
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    iota(f.begin(),f.end(),3);
    for(int i : f) cout<<i<<" ";
    return 0;
}