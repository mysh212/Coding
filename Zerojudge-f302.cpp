// Author : ysh
// 06/24/2022 Fri 10:31:35.24
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    int n = 0;
    for(char i : a) {
        assert(isdigit(i));
        n = (n * 9) + (i - '0');
    }
    cout<<n;
    return 0;
}