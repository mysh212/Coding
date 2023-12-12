// Author : ysh
// 2023/12/11 Mon 14:31:02
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        int ans = 0;
        while(n != 0) {
            ans = ans + (n / 5);
            n = n / 5;
        }
        outl(ans);
    }
    return 0;
}