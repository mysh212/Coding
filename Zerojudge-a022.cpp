// Author : ysh
// 03/28/2022 Mon 19:56:10.81
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    string b = a;
    reverse(a.begin(),a.end());
    if(b == a) cout<<"yes";
    else cout<<"no";
}