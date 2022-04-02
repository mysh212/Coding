// Author : ysh
// 03/27/2022 Sun 18:08:18.46
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        string a[n];
        for(string &i : a) {
            cin>>i;
        }
        sort(a,a+n);
        for(string i : a) {
            cout<<i<<"\n";
        }
    }
    return 0;
}