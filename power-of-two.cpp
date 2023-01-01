// Author : ysh
// 01/01/2023 Sun  8:49:39.11
// https://192.168.193.20/problem/55
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    if(n == 0) {
        cout<<1;
        return 0;
    }
    int c[] = {2,4,8,6};
    n = n % 4;
    n = n - 1;
    if(n < 0) n = n + 4;
    cout<<c[n];
    return 0;
}