// Author : ysh
// 04/05/2022 Tue  7:58:28.02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    {
    char n[3];
    itoa(a,n,10);
    reverse(n,n + 1000);
    a = atoi(n);
    }
    cout<<a;
}