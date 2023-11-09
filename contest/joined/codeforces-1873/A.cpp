// Author : ysh
// 2023/09/21 Thu 22:31:39
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string a;cin>>a;
        if(a == "acb" || a == "abc" || a == "cba" || a == "bac") cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}