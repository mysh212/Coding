// Author : ysh
// 06/08/2022 Wed 15:36:47.97
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    set<string>m;
    while(getline(cin,a)) {
        m.insert(a);
    }
    for(string i : m) {
        cout<<i<<"\n";
    }
    return 0;
}