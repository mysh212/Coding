// Author : ysh
// 2023/10/25 Wed 21:27:04
// https://codeforces.com/problemset/problem/1487/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        cout<<((int(sqrt((tmp << 1) - 1)) + 1) >> 1) - 1<<"\n";
    }
    return 0;
}