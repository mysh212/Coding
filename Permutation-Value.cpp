// Author : ysh
// 11/20/2022 Sun  7:17:51.00
// https://codeforces.com/contest/1743/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        cout<<1<<" ";
        for(int i = a;i>=2;i--) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}