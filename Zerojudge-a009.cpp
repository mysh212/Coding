// Author : ysh
// 04/06/2022 Wed 19:56:47.99
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a = "";
    getline(cin,a);
    for(char i : a) cout<<(char) (i - 7);
    return 0;
}