// Author : ysh
// 08/25/2022 Thu  8:41:36.40
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r = 9;
    function<int(int)> fac = [&](int n){ return (n < 2) ? 1 : r*fac(n-1); };
    cout<<fac(10);
}