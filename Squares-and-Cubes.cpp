// Author : ysh
// 2023/07/10 Mon 19:49:57
// https://codeforces.com/contest/1619/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<long long>f;
    for(long long i = 1;i<=sqrt(1e9);i++) (i == 1 ? void() : f.push_back(i * i)),f.push_back(i * i * i);
    sort(f.begin(),f.end());
    f.resize(unique(f.begin(),f.end()) - f.begin());
    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        cout<<int(upper_bound(f.begin(),f.end(),tmp) - f.begin())<<"\n";
    }
    return 0;
}