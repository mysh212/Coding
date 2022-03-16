// Author : ysh
// 01/08/2022 Sat 17:16:35.73
#include<bits/stdc++.h>
using namespace std;
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    map<int,int> m;
    m[1]=5;
    m[7]=6;
    m[9]=5;
    m[9]=7;
    cout<<m.find(7)->second<<" "<<m.erase(10);
}