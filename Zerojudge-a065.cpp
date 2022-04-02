// Author : ysh
// 04/01/2022 Fri 20:44:48.78
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int b = a.size();
    for(int i = 1;i<b;i++) {
        cout<<abs(((int)a.at(i)) - ((int) a.at(i - 1)));
    }
    cout<<"\n";
    return 0;
}