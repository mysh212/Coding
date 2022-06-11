// Author : ysh
// 06/06/2022 Mon  9:21:29.04
// https://192.168.193.20/contest/2/problem/025
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    n = n + 1;
    if(n & 1) {
        int tmp = ((n - 1) >> 1) + 1;
        cout<<tmp * tmp;
        return 0;
    }
    cout<<((((n + 2) * (n >> 1)) >> 1) << 1);
    return 0;
}