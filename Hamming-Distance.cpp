// Author : ysh
// 02/24/2023 Fri 19:44:35.71
// https://cses.fi/problemset/task/2136
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    bitset<31>s[a];
    for(int i = 0;i < a;i++) {
        string tmp;cin>>tmp;
        s[i] = bitset<31>(tmp);
    }
    int mmin = 32;
    for(int i = 0;i<a;i++) {
        for(int j = i + 1;j < a;j++) {
            bitset<31>tmp;
            tmp = s[i] ^ s[j];
            mmin = min((int) tmp.count(),mmin);
        }
    }
    cout<<mmin;
    return 0;
}