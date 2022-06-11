// Author : ysh
// 06/06/2022 Mon 18:50:06.53
// https://192.168.193.20/contest/2/problem/02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int tmp = abs(a - b);
    cout<<(long long) pow(32,tmp);
    return 0;
}