// Author : ysh
// 03/28/2022 Mon 19:59:41.93
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    reverse(a.begin(),a.end());
    cout<<stoi(a);
    return 0;
}