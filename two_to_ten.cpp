// Author : ysh
// 01/25/2022 Tue 13:52:59.65
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        int m = 0;
        int r = 0;
        while(n!=0) {
            m = m | ((n % 10) << r);
            r++;
            n = n / 10;
        }
        cout<<(char)m;
    }
}