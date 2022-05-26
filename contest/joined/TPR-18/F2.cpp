// Author : ysh
// 04/17/2022 Sun 14:49:35.24
#include<bits/stdc++.h>
using namespace std;
int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    printf("Hi, Sigma isn't Omega.");
    cout<<endl;
    string b;cin>>b;
    int a = stoi(b.substr(b.size() - 1,1));
    printf("! %d\n",(a & 1 ? 1 : 2));
    return 0;
}