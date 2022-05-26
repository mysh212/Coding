// Author : ysh
// 04/17/2022 Sun 14:55:10.45
#include<bits/stdc++.h>
using namespace std;
#define t ((a + b + c) / 2.0)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    cout<<(int) sqrt((t * (t - a) * (t - b) * (t - c)));
    return 0;
}