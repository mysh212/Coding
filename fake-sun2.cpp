// Author : ysh
// 02/06/2022 Sun 17:47:51.21
// http://choj.me/problem/00072
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    bitset<10000>v;
    int twice;
    int t = 0;
    while(cin>>n) {
        if(v.test(n) == 1) twice = n;
        v.set(n);
        t++;
    }
    n = t;
    int lost;
    for(int i = 1;i<=n;i++) {
        if(v.test(i) == 0) {
            cout<<twice<<" "<<i;
            break;
        }
    }
    return 0;
}