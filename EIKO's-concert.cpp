// Author : ysh
// 07/01/2022 Fri  6:28:45.19
// https://choj.me/problem/c001
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a,b;cin>>a>>b;
    int n;
    bool c = 1;
    while(cin>>n) {
        for(int i = 1;i<=n;i++) {
            cout<<(c ? a : b);
        }
        c = !c;
    }
    return 0;
}