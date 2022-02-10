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
    f.set();
    while(cin>>n) {
        if(n == 0) break;
        f.reset(n - 1);
        r++;
    }
    //cout<<f.to_string();
    for(int i = f._Find_first();i<r;i = f._Find_next(i)) {
        cout<<i + 1<<" ";
    }
    return 0;
}