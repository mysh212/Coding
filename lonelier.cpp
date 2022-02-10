// Author : ysh
// 02/08/2022 Tue 22:22:25.66
// http://choj.me/problem/00071
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bitset<60001>f;
    f.reset();
    while(n--) {
        int tmp;cin>>tmp;
        f.flip(tmp + 30000);
    }
    for(int i = 0;i<60001;i++) {
        if(f.test(i)) cout<<i-30000;
    }
    return 0;
}