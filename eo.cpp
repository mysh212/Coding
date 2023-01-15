// Author : ysh
// 04/06/2022 Wed 20:05:58.16
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    while(getline(cin,a)) {
        while(a.back() == ' ') {
            a.pop_back();
        }
        cout<<a<<"\n";
    }
    return 0;
}