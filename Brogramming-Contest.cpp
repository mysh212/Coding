// Author : ysh
// 2025/02/21 Fri 20:07:34
// https://codeforces.com/contest/2064/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        string a;cin>>a;
        a.resize(unique(a.begin(),a.end()) - a.begin());
        cout<<a.size() - (a.at(0) == '0' ? 1 : 0)<<"\n";
    }
    return 0;
}