// Author : ysh
// 02/09/2022 Wed 11:35:49.13
// http://choj.me/problem/00024
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<1000>f;
    int n;
    int r = 0;
    while(cin>>n) {
        if(n == 0) break;
        f.set(n - 1);
        r++;
    }
    for(int i = 0;i<r;i++) {
        if(f.test(i) == 0) cout<<i + 1<<" ";
    }
    return 0;
}