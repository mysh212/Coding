// Author : ysh
// 02/06/2023 Mon 20:28:36.65
// https://codeforces.com/gym/412932/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int r = (n / 14) * 3;
    n = n % 14;
    if(n >= 1 && n <= 8) r++;
    if(n >= 9 && n <= 10) r = r + 2;
    if(n >= 11 && n <= 13) r = r + 3;
    cout<<r;
    return 0;
}